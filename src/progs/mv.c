

#include "priv.h"

static struct
{
    const char* argv0;
} opt;

/* renameat(AT_FDCWD, files[i], destfd, destfn) */
static int do_rename(const char* filename, int destfd, const char* destfn)
{
    #if defined(MINIPLAT_ISWINNT)
        fprintf(stderr, "%s: missing implementation analogue to renameat(AT_FDCWD, ...)\n", opt.argv0);
    #else
        return renameat(AT_FDCWD, filename, destfd, destfn);
    #endif
    return -1;
}

static int copy_file(const char* source, int destfd, const char* destfn)
{
    char    buf[4096];
    ssize_t len;
    int     ifd, ofd;

    ifd = open(source, O_RDONLY);
    if(ifd < 0)
        return 1;
    ofd = openat(destfd, destfn, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if(ofd < 0)
        return 1;

    do
    {
        len = read(ifd, buf, sizeof(buf));
        if(len < 0)
            return 1;
        else if(len == 0)
            break;
        if(write(ofd, buf, len) != len)
            return 1;
    } while(len);
    close(ifd);
    close(ofd);
    if(unlink(source))
        return 1;
    return 0;
}

static int copy_file2(const char* source, const char* dest)
{
    char *copy, *destfn;
    int   destfd, ret;

    destfd = open(dest, O_RDONLY);
    if(destfd < 0)
        return 1;

    copy = strdup(source);
    if(!copy)
        return 1;
    destfn = basename(copy);
    ret = copy_file(source, destfd, destfn);
    free(copy);
    close(destfd);
    return ret;
}

static int multi_move(int len, const char** files, const char* dest)
{
    int i;
    int destfd;
    char* copy;
    char* destfn;
    struct stat stbuf;


    destfd = open(dest, O_RDONLY);
    if(destfd < 0)
    {
        fprintf(stderr, "%s: %s: %s\n", opt.argv0, dest, strerror(errno));
        return 1;
    }
    if(fstat(destfd, &stbuf) || !S_ISDIR(stbuf.st_mode))
    {
        fprintf(stderr, "%s: %s: not a directory\n", opt.argv0, dest);
        return 1;
    }
    for(i = 0; i < len; i++)
    {
        copy = strdup(files[i]);
        if(!copy)
        {
            fprintf(stderr, "%s: %s\n", opt.argv0, strerror(errno));
            return 1;
        }
        destfn = basename(copy);
        
        
        if(do_rename(files[i], destfd, destfn))
        {
            if(errno == EXDEV && !copy_file(files[i], destfd, destfn))
            {
                free(copy);
                continue;
            }
            fprintf(stderr, "%s: %s: %s\n", opt.argv0, files[i], strerror(errno));
            return 1;
        }

        free(copy);
    }
    close(destfd);
    return 0;
}

/* Usage: mv FILES... DEST */
MINISTARTMAIN(mv)
{
    UNUSED(envp);
    opt.argv0 = argv[0];
    if(argc == 2)
    {
        fprintf(stderr, "%s: missing destination\n", argv[0]);
        return 1;
    }
    else if(argc == 3)
    {
        const char *source, *dest;

        source = argv[1];
        dest = argv[2];
        if(rename(source, dest))
        {
            if(errno == EXDEV && !copy_file2(source, dest))
                return 0;
            fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
            return 1;
        }
    }
    else
    {
        return multi_move(argc - 2, (const char**)(argv + 1), (const char*)argv[argc - 1]);
    }
    return 0;
}
