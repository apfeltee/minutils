

#include "priv.h"


/* Usage: tee [-a] [FILE...] */
MINISTARTMAIN(tee)
{
    int i;
    int ret;
    int flags;
    ssize_t n;
    char    buf[4096];
    struct
    {
        int* fds;
        int  len;
    } files;
    UNUSED(envp);
    if(!strcmp(argv[1], "-a"))
    {
        flags = O_APPEND;
        files.len = argc - 1;
        i = 2;
    }
    else
    {
        flags = O_TRUNC;
        files.len = argc;
        i = 1;
    }

    files.fds = malloc(files.len * sizeof(int));
    if(!files.fds)
    {
        fprintf(stderr, "%s: unable to allocate: %s\n", argv[0], strerror(errno));
        return -1;
    }
    files.fds[0] = STDOUT_FILENO;
    for(; i < argc; i++)
    {
        files.fds[i] = open(argv[i], O_CREAT | O_WRONLY | flags, 0666);
        if(files.fds[i] < 0)
            return 1;
    }
    while((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
    {
        for(i = 0; i < argc; i++)
        {
            if(write(files.fds[i], buf, n) != n)
            {
                fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
                return 1;
            }
        }
    }

    ret = 0;
    for(i = 1; i < argc; i++)
        close(files.fds[i]);
    free(files.fds);
    return ret;
}
