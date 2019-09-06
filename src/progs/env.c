

#include "priv.h"

static void print_env(void)
{
    const char** env;

    for(env = (const char**)environ; *env; env++)
        puts(*env);
}

/* Usage: env [VARIABLE=value] [PROGRAM [ARGUMENTS]] */
MINISTARTMAIN(env)
{
    char* val;
    int   i;
    (void)envp;
    for(i = 1; i < argc; i++)
    {
        val = strchr(argv[i], '=');
        if(!val)
            break;
        val[0] = '\0';
        val++;
        if(setenv(argv[i], val, 1))
        {
            fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
            return 1;
        }
    }
    if(i == argc)
    {
        print_env();
        return 0;
    }
    execvp(argv[i], argv + i);
    fprintf(stderr, "%s: %s: unable to exec: %s\n", argv[0], argv[i], strerror(errno));
    return 1;
}
