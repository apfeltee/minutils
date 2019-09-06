
#include "priv.h"

#define UNUSED(x) ((void)(x))

/* Usage: whoami */
MINISTARTMAIN(whoami)
{
    struct passwd* pw;
    uid_t          uid;

    UNUSED(argc);
    UNUSED(envp);
    uid = geteuid();
    pw = getpwuid(uid);
    if(!pw)
    {
        fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
        return 1;
    }

    printf("%s\n", pw->pw_name);
    return 0;
}
