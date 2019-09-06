
#include "priv.h"

MINISTARTMAIN(unlink)
{
    int i;
    int ret;
    UNUSED(envp);
    if(argc < 2)
    {
        fprintf(stderr, "%s: missing operand\n", argv[0]);
        return 1;
    }

    ret = 0;
    for(i = 1; i < argc; i++)
    {
        if(unlink(argv[i]))
        {
            fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
            ret = 1;
        }
    }
    return ret;
}
