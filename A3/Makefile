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

BSTSRC = $(SRCDIR)bst.c $(SRCDIR)bstMain.c
PROGSRC = $(SRCDIR)bst.c $(SRCDIR)functions.c $(SRCDIR)progMain.c
FILESRC = $(SRCDIR)fileTest.c

#The names of the binary programs that will be produced.  
#
BSTNAME = $(BINDIR)search
PROGNAME = $(BINDIR)run
FILENAME = $(BINDIR)fileTest

all : testing program


binary:
	$(CC) $(CFLAGS) $(BSTSRC) -o $(BSTNAME) $(INCLUDES)

program:
	$(CC) $(CFLAGS) -D_BSD_SOURCE $(PROGSRC) -o $(PROGNAME) $(INCLUDES)

file:
	$(CC) $(CFLAGS) -D_BSD_SOURCE $(FILESRC) -o $(FILENAME) $(INCLUDES)

clean:
	@ rm *.o



