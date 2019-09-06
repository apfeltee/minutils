
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#define _DEFAULT_SOURCE

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


#if defined(__CYGWIN__)
    #define MINIPLAT_ISWINNT
    #define MINIPLAT_ISCYGWIN
#endif

/* probably nonportable headers */
#if defined(__unix__) || defined(__CYGWIN__)
    #include <utime.h>
    #include <sys/utsname.h>
    #include <sys/resource.h>
    #include <sys/sysmacros.h>
    #include <sys/mman.h>
    #include <sys/vfs.h>
    #include <libgen.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #define MINIPLAT_ISUNIX
#elif defined(_MSC_VER)
    #include <windows.h>
    #include <io.h>
    #if !defined(MINIPLAT_ISWINNT)
        #define MINIPLAT_ISWINNT
    #endif
    #define ssize_t  size_t
    #define pid_t    int
    #define mode_t   int
    #if !defined(SIGKILL)
        #define SIGKILL 9
    #endif
#endif

#include "getopt.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define UNUSED(x) ((void)(x))

#define fail(...) \
    { \
        fprintf(stderr, "ERROR: "); \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    }

#define MINISTARTMAIN(name) \
    int miniprog_##name##_main(int argc, char** argv, char** envp)

typedef struct minicontext_tag_t   minicontext_t;
typedef struct miniproginfo_tag_t  miniproginfo_t;
typedef int(*minimainfn_t)(int, char**, char**);

struct minicontext_tag_t
{
    const char* selfexe;
};

struct miniproginfo_tag_t
{
    char name[255];
    char filename[255];
    minimainfn_t mainfunc;
};


