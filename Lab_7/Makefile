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

PROGSRC = $(SRCDIR)bubble.c $(SRCDIR)main.c

#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)sort


all : testing program

bubble: 
	$(CC) $(CFLAGS) $(PROGSRC) -o $(PROGNAME) $(INCLUDES)

clean:
	@ rm *.o



