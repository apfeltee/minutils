
#include "priv.h"

/* Usage: echo [TEXT...] */
MINISTARTMAIN(echo)
{
    int i;
    (void)envp;
    if(argc == 1)
    {
        putchar('\n');
        return 0;
    }
    for(i = 1; i < argc; i++)
    {
        fputs(argv[i], stdout);
        if(i < argc - 1)
            putchar(' ');
    }
    putchar('\n');
    return 0;
}
