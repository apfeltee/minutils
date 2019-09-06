
#include "priv.h"

/* Usage sync [PATH...] */
MINISTARTMAIN(sync)
{
    int i;
    UNUSED(envp);
    if(argc == 1)
    {
        sync();
    }
    else
        for(i = 1; i < argc; i++)
        {
            int fd;

            fd = open(argv[i], O_WRONLY);
            if(fd < 0)
            {
                goto fail;
            }
            if(fsync(fd))
            {
                goto fail;
            }
            if(close(fd))
            {
                goto fail;
            }
        }

    return 0;
fail:
    fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
    return 1;
}
