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

HASH = $(SRCDIR)hash.c $(SRCDIR)main.c
LIST = $(SRCDIR)list.c $(SRCDIR)main.c

#The names of the binary programs that will be produced.  
#
HASHNAME = $(BINDIR)hash
LISTNAME = $(BINDIR)list


all : testing program


hash:
	$(CC) $(CFLAGS) $(HASH) -o $(HASHNAME) $(INCLUDES)

list:
	$(CC) $(CFLAGS) $(LIST) -o $(LISTNAME) $(INCLUDES)


clean:
	@ rm *.o



