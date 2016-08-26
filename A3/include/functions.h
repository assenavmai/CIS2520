/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: MENU
 *LAST MODIFICATION: August 1st, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/limits.h>
#include <ctype.h>
#include <sys/stat.h>
#include "bst.h"

#define BUFFERSIZE 256


/*open the directories
 *@param Tree *: Tree
 *@param const char *: directory name
 * no return
 */
void openDirectories(Tree * theTree, const char * dir_name);

/*open the directories
 *@param Tree *: Tree
 *@param const char *: directory name
 * no return
 */
void getDirectory(Tree * theTree, const char * parent);

/*get user input
 *@param char *: userinput
 * no return
 */
void getInput(char * input);

/*displays menu
 * returns menu option
 */
int displayMenu();

/*get user input
 *@param char *: file names and path names
 * no return
 */
void renameFile(char * pathname, char * oldFilename, char * newFilename);

/*get user input
 *@param char *: path name and file name
 * no return
 */
void deleteFile(char * pathname, char * toDelete);
