
#include "priv.h"

/* yes [TEXT...] */
MINISTARTMAIN(yes)
{
    size_t len;
    char   buf[8192];
    UNUSED(envp);
    if(argc == 1)
    {
        for(len = 0; len < sizeof(buf); len += 2)
        {
            buf[len] = 'y';
            buf[len + 1] = '\n';
        }
    }
    else
    {
        size_t slen;
        int    i;

        i = 1;
        len = 0;
        while(len < sizeof(buf))
        {
            slen = strlen(argv[i]);
            if(len + slen + 1 >= sizeof(buf))
                break;

            memcpy(buf + len, argv[i], slen);
            len += slen;
            if(i < argc - 1)
                buf[len++] = ' ';
            if(++i == argc)
            {
                i = 1;
                buf[len++] = '\n';
            }
        }
    }

    for(;;)
    {
        if(write(STDOUT_FILENO, buf, len) < 0)
            return 1;
    }
    return 0;
}
