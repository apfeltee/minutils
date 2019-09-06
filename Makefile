
CC      = clang -Wall -Wextra
CFLAGS  = -Isrc
CFLAGS += -O3
LFLAGS += -O3
#CFLAGS += -g3 -ggdb
#LFLAGS  = -g3 -ggdb

##########################
RM = rm -f

##########################
# ---------------------- #
##########################

exename          = mini.exe
headers          = src/priv.h
sources_lib      = src/util.c src/getopt.c $(wildcard src/progs/*.c)
sources_exe      = src/main.c
objects_lib      = $(sources_lib:.c=.o)
objects_exe      = $(sources_exe:.c=.o)
objects          = $(objects_lib) $(objects_exe)
sources          = $(sources_lib) $(sources_exe)

##########################

.PHONY: all

all: $(exename)

$(exename): $(headers) $(objects)
	$(CXX) $(objects) -o $(exename) $(LFLAGS)


%.o: %.c $(headers)
	$(CC) -c $< -o $@ $(CFLAGS)

src/progs/basename.c: $(headers)
src/progs/cat.c: $(headers)
src/progs/chmod.c: $(headers)
src/progs/chown.c: $(headers)
src/progs/cmp.c: $(headers)
src/progs/cp.c: $(headers)
src/progs/dirname.c: $(headers)
src/progs/echo.c: $(headers)
src/progs/env.c: $(headers)
src/progs/false.c: $(headers)
src/progs/getloadavg.c: $(headers)
src/progs/head.c: $(headers)
src/progs/id.c: $(headers)
src/progs/kill.c: $(headers)
src/progs/ln.c: $(headers)
src/progs/ls.c: $(headers)
src/progs/mkdir.c: $(headers)
src/progs/mkfifo.c: $(headers)
src/progs/mknod.c: $(headers)
src/progs/mktemp.c: $(headers)
src/progs/mv.c: $(headers)
src/progs/nice.c: $(headers)
src/progs/nl.c: $(headers)
src/progs/nohup.c: $(headers)
src/progs/printenv.c: $(headers)
src/progs/printf.c: $(headers)
src/progs/pwd.c: $(headers)
src/progs/readlink.c: $(headers)
src/progs/realpath.c: $(headers)
src/progs/rev.c: $(headers)
src/progs/rm.c: $(headers)
src/progs/rmdir.c: $(headers)
src/progs/seq.c: $(headers)
src/progs/shred.c: $(headers)
src/progs/shuf.c: $(headers)
src/progs/sleep.c: $(headers)
src/progs/sort.c: $(headers)
src/progs/stat.c: $(headers)
src/progs/strings.c: $(headers)
src/progs/sync.c: $(headers)
src/progs/tee.c: $(headers)
src/progs/test.c: $(headers)
src/progs/timeout.c: $(headers)
src/progs/touch.c: $(headers)
src/progs/true.c: $(headers)
src/progs/truncate.c: $(headers)
src/progs/tty.c: $(headers)
src/progs/uname.c: $(headers)
src/progs/uniq.c: $(headers)
src/progs/unlink.c: $(headers)
src/progs/uptime.c: $(headers)
src/progs/wc.c: $(headers)
src/progs/which.c: $(headers)
src/progs/whoami.c: $(headers)
src/progs/yes.c: $(headers)


clean:
	$(RM) $(objects)

distclean: clean
	$(RM) $(exename)

rebuild: distclean all



