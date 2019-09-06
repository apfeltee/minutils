
#include "priv.h"




MINISTARTMAIN(getloadavg)
{
    double up[3];
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(envp);
    if(getloadavg(up, ARRAY_SIZE(up)) < 0)
    {
        fprintf(stderr, "%s: getloadavg() failed\n", argv[0]);
        return 1;
    }

    printf("%.2f %.2f %.2f\n", up[0], up[1], up[2]);
    return 0;
}
