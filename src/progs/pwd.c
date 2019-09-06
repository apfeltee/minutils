

#include "priv.h"

#define UNUSED(x) ((void)(x))

/* Usage: pwd */
MINISTARTMAIN(pwd)
{
    char cwd[PATH_MAX];

    UNUSED(argc);
    UNUSED(envp);

    if(getcwd(cwd, sizeof(cwd)))
    {
        printf("%s\n", cwd);
    }
    else
    {
        fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
        return 1;
    }
    return 0;
}
