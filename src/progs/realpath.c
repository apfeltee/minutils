

#include "priv.h"

static const char* argv0;

static int do_realpath(const char* path)
{
    char buf[PATH_MAX];

    if(!realpath(path, buf))
    {
        fprintf(stderr, "%s: %s: %s\n", argv0, path, strerror(errno));
        return -1;
    }
    puts(buf);
    return 0;
}

/* Usage: realpath [FILE...] */
MINISTARTMAIN(realpath)
{
    int i;
    int ret;
    UNUSED(envp);
    argv0 = argv[0];
    for(i = 1; i < argc; i++)
    {
        if(argv[i][0] != '-')
        {
            break;
        }
        else
        {
            fprintf(stderr, "%s: invalid argument: %s\n", argv[0], argv[i]);
            return 1;
        }
    }

    ret = 0;
    for(; i < argc; i++)
    {
        if(do_realpath(argv[i]))
            ret = 1;
    }
    return ret;
}
