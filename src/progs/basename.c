
#include "priv.h"

static void remove_suffix(char* base, const char* suffix)
{
    size_t baselen, suflen;
    char*  ptr;

    baselen = strlen(base);
    suflen = strlen(suffix);

    ptr = base + baselen - suflen;
    if(!strcmp(ptr, suffix))
        *ptr = '\0';
}

/* Usage: basename PATH [SUFFIX] */
MINISTARTMAIN(basename)
{
    const char* suffix;
    char*       base;
    (void)argc;
    (void)argv;
    (void)envp;
    switch(argc)
    {
        case 2:
            suffix = NULL;
            break;
        case 3:
            suffix = argv[2];
            break;
        default:
            fprintf(stderr, "%s: missing operand\n", argv[0]);
            return 1;
    }
    base = basename(argv[1]);
    if(suffix)
        remove_suffix(base, suffix);

    puts(base);
    return 0;
}
