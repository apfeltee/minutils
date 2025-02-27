
#include "priv.h"



static struct
{
    const char* argv0;
    int         signum;
} opt;

static const struct sig_entry
{
    const char* name;
    int         signum;
} sig_table[] = {
    { "HUP", 1 },
    { "INT", 2 },   { "QUIT", 3 },  { "ILL", 4 },     { "TRAP", 5 },    { "ABRT", 6 },
    { "IOT", 6 },    { "BUS", 7 },   { "FPE", 8 },   { "KILL", 9 },    { "USR1", 10 },   { "SEGV", 11 },
    { "USR2", 12 },  { "PIPE", 13 }, { "ALRM", 14 }, { "TERM", 15 },   { "STKFLT", 16 }, { "CHLD", 17 },
    { "CLD", 17 },   { "CONT", 18 }, { "STOP", 19 }, { "TSTP", 20 },   { "TTIN", 21 },   { "TTOU", 22 },
    { "URG", 23 },   { "XCPU", 24 }, { "XFSZ", 25 }, { "VTALRM", 26 }, { "PROF", 27 },   { "WINCH", 28 },
    { "IO", 29 },    { "POLL", 29 }, { "PWR", 30 },  { "UNUSED", 31 }, { "SYS", 31 },    { "RTMIN", 34 },
    { "RTMAX", 64 },
};

static long parse_int(const char* str)
{
    long  val;
    char* ptr;

    val = strtol(str, &ptr, 0);
    if(!*str || *ptr || errno)
        return -1;
    return val;
}

static int get_signum(const char* name)
{
    const struct sig_entry* ent;
    int                     signum;
    size_t                  i;

    signum = parse_int(name);
    if(0 <= signum && signum <= NSIG)
        return signum;

    if(!strncasecmp(name, "SIG", 3))
        name += 3;

    for(i = 0; i < ARRAY_SIZE(sig_table); i++)
    {
        ent = &sig_table[i];
        if(!strcasecmp(ent->name, name))
            return ent->signum;
    }
    fprintf(stderr, "%s: invalid signal: %s\n", opt.argv0, name);
    exit(1);
}

static void print_table(void)
{
    const struct sig_entry* ent;
    size_t                  i;

    for(i = 0; i < ARRAY_SIZE(sig_table); i++)
    {
        ent = &sig_table[i];
        printf("%2d %-7s ", ent->signum, ent->name);
        if(i % 10 == 9)
            putchar('\n');
    }
}

static void print_names(int signum)
{
    const struct sig_entry* ent;
    size_t                  i, j;

    j = 0;
    for(i = 0; i < ARRAY_SIZE(sig_table); i++)
    {
        ent = &sig_table[i];
        if(signum < 0 || signum == ent->signum)
        {
            printf("%s ", ent->name);
            if(j++ == 15)
            {
                putchar('\n');
                j = 0;
            }
        }
    }
}

/* Usage: kill [-SIGNAL] PID... */
/* Usage: kill -l [NUMBER] */
/* Usage: kill -L */
MINISTARTMAIN(kill)
{
    int i;
    int ret;
    int signum;
    pid_t pid;
    UNUSED(envp);
    if(argc == 1)
    {
        fprintf(stderr, "%s: missing operand\n", argv[0]);
        return 1;
    }

    opt.argv0 = argv[0];
    opt.signum = SIGTERM;

    if(!strcmp(argv[1], "-L"))
    {
        print_table();
        return 0;
    }
    else if(!strcmp(argv[1], "-l"))
    {
        if(argc > 2)
            signum = get_signum(argv[2]);
        else
            signum = -1;

        print_names(signum);
        return 0;
    }
    else if(argv[1][0] == '-')
    {
        opt.signum = get_signum(argv[1] + 1);
        i = 2;
    }
    else
    {
        i = 1;
    }

    ret = 0;
    for(; i < argc; i++)
    {
        pid = parse_int(argv[i]);
        if(kill(pid, opt.signum))
        {
            fprintf(stderr, "%s: %d: %s\n", opt.argv0, pid, strerror(errno));
            ret = 1;
        }
    }
    return ret;
}
