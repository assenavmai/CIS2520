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

TESTSRC = $(SRCDIR)linkedList.c $(SRCDIR)test.c $(SRCDIR)hash.c $(SRCDIR)functions.c
PROGSRC = $(SRCDIR)list.c $(SRCDIR)load.c $(SRCDIR)program.c
HASHSRC = $(SRCDIR)hash.c $(SRCDIR)linkedList.c $(SRCDIR)hashMain.c

#The names of the binary programs that will be produced.  
#
TESTNAME = $(BINDIR)runTests
PROGNAME = $(BINDIR)simulation
HASHNAME = $(BINDIR)hash


all : testing program


testing:
	$(CC) $(CFLAGS) $(TESTSRC) -o $(TESTNAME) $(INCLUDES)


program: 
	$(CC) $(CFLAGS) $(PROGSRC) -o $(PROGNAME) $(INCLUDES)

table:
	$(CC) $(CFLAGS) $(HASHSRC) -o $(HASHNAME) $(INCLUDES)

clean:
	@ rm *.o



