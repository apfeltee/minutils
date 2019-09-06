
#include "priv.h"
#include "generated_proginfo.h"

miniproginfo_t* get_prog_by_name(const char* name)
{
    int i;
    for(i=0; miniprogdefinitions[i].mainfunc != NULL; i++)
    {
        if(strcmp(miniprogdefinitions[i].name, name) == 0)
        {
            return &miniprogdefinitions[i];
        }
    }
    return NULL;
}

int main(int argc, char* argv[], char* envp[])
{
    const char* progname;
    miniproginfo_t* inf;
    if(argc > 1)
    {
        progname = argv[1];
        if((inf = get_prog_by_name(progname)) != NULL)
        {
            return inf->mainfunc(argc - 1, argv + 1, envp);
        }
        else
        {
            fail("no such command: %s", progname);
        }
    }
    else
    {
        fail("usage: %s <progname> [<arguments> ...]", argv[0]);
    }
}
