
#include "priv.h"


/* Usage: mkfifo [PATH...] */
MINISTARTMAIN(mkfifo)
{
    int i;
    UNUSED(envp);
    if(argc == 1)
    {
        fprintf(stderr, "%s: missing operand\n", argv[0]);
        return 1;
    }
    for(i = 1; i < argc; i++)
    {
        if(mkfifo(argv[i], 0666))
        {
            fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
            return 1;
        }
    }
    return 0;
}
