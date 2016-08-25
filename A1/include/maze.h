/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Function prototypes and define statements for maze.c
 *LAST MODIFICATION: June 6th, 2014
 */
#include "stack.h"
#include <time.h>

/*defining for the maze program*/
#define BUFFERSIZE 201
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#define START 'S'
#define FINISH 'F'
#define VISITED 'v'
#define ONPATH '#'
#define NOTONPATH 'x'
#define WALLP '+'
#define WALLD '-'
#define WALLH '|'
#define PATH ' '

/*Description:
 *Opens text file
 *Parameters:
 *argc: amount of argument entered into terminal
 * argv[]: takes the second argument as the file name
 *Return:
 *Returns the opened file
 */
FILE * openFile(int argc, char const * argv[]);

/*Description:
 *Mallocs for char ** pointer
 *Parameters:
 *holdMaze: char ** array going to hold file
 *Return:
 *The maze malloced
 */
char ** mallocMaze(char ** holdMaze);

/*Description:
 *Prints the maze
 *Parameters:
 *maze: the maze file stored
 *amountRows: amount of rows in the text file
 *amountCols: amount of cols in textfile
 *rStack: stack for the rows
 *cStack: stack for the cols
 *Return:
 *None
 */
void printMaze(char ** maze, int amountRows, int amountCols, Stack * rStack, Stack * cStack);

/*Description:
 *Prints the maze
 *Parameters:
 *maze: the maze file stored
 *nRow: amount of rows in the text file
 *nCol: amount of cols in textfile
 *rowStack: stack for the rows
 *colStack: stack for the cols
 *startR: starting position in rows
 *startC: starting position in cols
 *Return:
 *None
 */
void findStart(char ** maze, int nRow, int nCol, Stack * rowStack, Stack * colStack, int startR, int startC);
