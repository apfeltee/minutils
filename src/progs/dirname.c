
#include "priv.h"

/* Usage: dirname PATH... */
MINISTARTMAIN(dirname)
{
    int i;
    (void)envp;
    if(argc < 2)
    {
        fprintf(stderr, "%s: missing operand\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
        puts(dirname(argv[i]));
    return 0;
}
