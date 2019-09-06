
#include "priv.h"

enum
{
    PERM_REMOVE,
    PERM_ADD,
    PERM_SET
};

static int is_octal(mode_t* mode, const char* str)
{
    size_t i;

    for(i = 0; str[i]; i++)
    {
        if('0' > str[i] || str[i] > '7')
            return 0;

        *mode <<= 3;
        *mode += str[i] - '0';
    }
    return 1;
}

static mode_t parse_mode(const char* str)
{
    size_t i;
    mode_t mode;
    struct
    {
        bool user : 1;
        bool group : 1;
        bool other : 1;
    } flags = {0, 0, 0};
    UNUSED(flags);
    mode = 0;
    if(is_octal(&mode, str))
        return mode;


    for(i = 0; str[i]; i++)
    {
        switch(str[0])
        {
            case 'u':
                flags.user = 1;
                break;
            case 'g':
                flags.group = 1;
                break;
            case 'o':
                flags.other = 1;
                break;
            case 'a':
                flags.user = 1;
                flags.group = 1;
                flags.other = 1;
                break;
            default:
                /* TODO */
                break;
        }
    }
    return mode;
}

/* Usage: chmod MODE FILE... */
MINISTARTMAIN(chmod)
{
    mode_t mode;
    UNUSED(envp);
    UNUSED(mode);
    if(argc < 3)
    {
        fprintf(stderr, "usage: %s MODE FILE...\n", argv[0]);
        return 1;
    }

    mode = parse_mode(argv[1]);
    /* todo: draw the rest of the f****** owl */
    return 0;
}
