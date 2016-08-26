/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: header file for functions.c
 *LAST MODIFICATION: July 4th, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

/*Opens a file
 *@param input: file name user entered
 *returns opened file
 */
FILE * openFile(char * input);

/*displays menu for user interaction
 *returns option they chose
 */
int displayMenu();
