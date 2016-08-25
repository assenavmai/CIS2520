CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/

#Put the names of your source code file in the lines below.  

TESTSRC = $(SRCDIR)list.c $(SRCDIR)stack.c $(SRCDIR)testing.c
PROGSRC = $(SRCDIR)list.c $(SRCDIR)stack.c $(SRCDIR)maze.c $(SRCDIR)simulation.c

#The names of the binary programs that will be produced.  
#
TESTNAME = $(BINDIR)runTests
PROGNAME = $(BINDIR)simulation


all : testing program


testing:
	$(CC) $(CFLAGS) $(TESTSRC) -o $(TESTNAME) $(INCLUDES)


program: 
	$(CC) $(CFLAGS) $(PROGSRC) -o $(PROGNAME) $(INCLUDES)

clean:
	@ rm *.o



