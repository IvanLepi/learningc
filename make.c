/*
* Make - Building large programs
*/

Tool for building large programs

Specifics:
Targets : Things to build
Dependencies : input to build targets from
Recipes : To build a target from what it depends on 

When make is run, it starts from a particular target - something
that can be built from other things. A common starting target might
be your entire program.
Make first checks if the target is up to date. Checking if the target
is up to date requires checking that all the files target depends on are 
themselfes up to date and that none of them are newer than the target. 
For example the target for the whole programm might depend on on many
object files. if any of those files is not up to date it is rebuilt first.
Make then follows whatever rule was specified for the target to build
it from the dependencies. IF the target is already up to date then it does 
nothing.

Large complicated programs may require linking with many libraries as well
as many command line options. Trying to remember all of these and type them
every time you compile is painfull.
Even worse, many real programs need to be compiled by other people - 
whether that is multiple members of a dev team or people you distribute 
the program to. Providing a Makefile allows everyone to build a program
simply by typing make.

myProgram: oneFile.o anotherFile.o
    gcc -o myProgram oneFile.o anotherFile.o
oneFile.o: oneFile.c oneHeader.h someHeader.h
    gcc -std=gnu99 -pedantic -Wall -c oneFile.c
anotherFile.o: anotherFile.o anotherHeader.h someHeader.h
    gcc -std=gnu99 -pedantic -Wall -c anotherFile.c

CFLAGS=-std=gnu99 -pedantic -Wall
myProgram: oneFile.o anotherFile.o
    gcc -o myProgram oneFile.o anotherFile.o
oneFile.o: oneFile.c oneHeader.h someHeader.h
    gcc $(CFLAGS) -c oneFile.c
anotherFile.o: anotherFile.o anotherHeader.h someHeader.h
    gcc -$(CFLAGS)-c anotherFile.c

Clean
A common target to put in a makefile is a clean target.
Target is intended to remove the compiled program, all obj files, all
editor backups, and any other files you might consider to be cluter.
This target is used to either force the program to be rebuilt or you 
just need to clean up the directory leaving only the source files.
.PHONY: clean
clean: 
    rm -f myProgram  *.o *.c~ *.h~

Generic rules

CC = gcc
CFLAGS=-std=gnu99 -pedantic -Wall
myProgram: oneFile.o anotherFile.o
    gcc -o myProgram oneFile.o anotherFile.o
.PHONY: clean depend
clean: 
    rm -f myProgram *.o *.c~ *.h~
depend:
    makedepend: anotherFile.c oneFile.c
#DONOTDELETE
anotherFile.o anotherHeader.h someHeader.h
oneFile.o oneHeader.h someHeader.h

Built in functions
Building optimized and debug object files.

CC = gcc
CFLAGS=-std=gnu99 -pedantic -Wall
DBFLAGS=-std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS=$(WILDCARD *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %c,%.dbg.o,$(SRCS))
.PHONY: clean depend all
all: myProgram myProgram-debug
myProgram: $(OBJS)
    gcc -o $@ $(OBJS)
myProgram-debug: $(DBOBJS)
    gcc -o $@ $(DBOBJS)
%.dbg.o: %.c
    gcc $(DBFLAGS) -c -o $@ $<
clean: 
    rm -f myProgram myProgram-debug *.o *.c~ *.h~
depend:
    makedepend: $(SRCS)
    makedepend: -a -o .dbg.o $(SRCS)
#DO NOT DELETE
anotherFile.o anotherHeader.h someHeader.h
oneFile.o oneHeader.h someHeader.h


gcc -Wall -Wsign-compare -Wwrite-strings Wtype-limits -Werror
