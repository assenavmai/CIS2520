/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Creating functions for the maze
 *LAST MODIFICATION: June 6th, 2014
 */
#include "maze.h"

/*preconditions: user inputs a filename when running the program (provides 2 arguments)
 *postconditions: the file is opened for use
*/
FILE * openFile(int argc, char const * argv[])
{
    FILE * file;

    if (argc != 2)/*If they do not put a file name in the terminal, exit*/
    { 
      printf("Usage: Enter an input file name\n");
      exit(1);
    }
    else
    {
        file = fopen(argv[1], "r");
    }

    return file;
}

/*preconditions: An initialized 2D pointer is passed in as the parameter
 *postconditions: the char ** array is malloced and returned
*/
char ** mallocMaze(char ** holdMaze)
{
    int i;

    holdMaze = malloc(sizeof(char *) * BUFFERSIZE + 1);

    if(holdMaze == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }

    for(i = 0; i < BUFFERSIZE; i++)
    {
        holdMaze[i] = malloc(sizeof(char) * BUFFERSIZE);

        if(holdMaze[i] == NULL)
        {
            printf("Out of memory\n");
            exit(1);
        }
    }

    return holdMaze;
}

/*preconditions: An initialized char ** array, the amount of rows and cols in the file, and 2 stacks are passed as the paramters
 *postconditions: The file is printed
*/
void printMaze(char ** maze, int amountRows, int amountCols, Stack * rStack, Stack * cStack)
{
    int i, j;

    for ( i = 0; i < amountRows; i++ )
    {
        for ( j = 0; j < amountCols; j++ )
        {
            if(maze[i][j] == '*')
            {
                fputc(maze[i][j], stdout);
            }
            else if(maze[i][j] == START || maze[i][j] == FINISH)
            {
                fputc(maze[i][j], stdout);
            }
            else if(maze[i][j] == ONPATH)
            {
                fputc(maze[i][j], stdout);
            }
            else
            {
                fputc(maze[i][j], stdout);
            }
        
        }
    }
}

/*preconditions: An initialized char ** array, the amount of rows and cols in the file, and 2 stacks are passed as the paramters
 *postconditions: Solves the maze
*/
void findStart(char ** maze, int nRow, int nCol, Stack * rowStack, Stack * colStack, int startR, int startC)
{
    /*Declaring variables*/
    int j;
    int direction, dirNext;

    /*Declaration of variables*/
    direction = 0;
    dirNext = 0;

    if(maze[startR][startC+1] == PATH)/*if there right, is a path go right*/
    {
        direction = RIGHT;
    }
    else if(maze[startR+1][startC] == PATH)/*if there path down, go down*/
    {
        direction = DOWN;
    }
    else if(maze[startR][startC-1] == PATH)/*if path left, go left*/
    {
        direction = LEFT;
    }
    else if(maze[startR-1][startC] == PATH)/*if path up, go up*/
    {
        direction = UP;
    }
    
    for(j = startC; j < nRow * nCol + 2; j++)/*for the size of the maze*/
    {
        if(maze[startR][startC] != START)
        {
            maze[startR][startC] = VISITED;
        }

        switch(direction)/*set direction next to move and then it will go that direction: eg. dirNext = 1, go down next time*/
        {
            case RIGHT:
                if(maze[startR][startC+1] != WALLP && maze[startR][startC+1] != WALLD && maze[startR][startC+1] != WALLH 
                    && maze[startR][startC+1] != START)
                {
                    dirNext = 1;
                    startC++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR-1][startC] != WALLP && maze[startR-1][startC] != WALLD && maze[startR-1][startC] != WALLH 
                    && maze[startR-1][startC] != START)
                {
                    dirNext = 0;
                    startR--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC-1] != WALLP && maze[startR][startC-1] != WALLD && maze[startR][startC-1] != WALLH 
                    && maze[startR][startC-1] != START)
                {
                    dirNext = 3;
                    startC--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR+1][startC] != WALLP && maze[startR+1][startC] != WALLD && maze[startR+1][startC] != WALLH 
                    && maze[startR+1][startC] != START)
                {
                    dirNext = 2;
                    startR++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                break;
            case DOWN:
                if(maze[startR+1][startC] != WALLP && maze[startR+1][startC] != WALLD && maze[startR+1][startC] != WALLH 
                    && maze[startR+1][startC] != START)
                {
                    dirNext = 2;
                    startR++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC+1] != WALLP && maze[startR][startC+1] != WALLD && maze[startR][startC+1] != WALLH 
                    && maze[startR][startC+1] != START)
                {
                    dirNext = 1;
                    startC++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR-1][startC] != WALLP && maze[startR-1][startC] != WALLD && maze[startR-1][startC] != WALLH 
                    && maze[startR-1][startC] != START)
                {
                    dirNext = 0;
                    startR--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC-1] != WALLP && maze[startR][startC-1] != WALLD && maze[startR][startC-1] != WALLH 
                    && maze[startR][startC-1] != START)
                {
                    dirNext = 3;
                    startC--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }               
                break;
            case LEFT:
                if(maze[startR][startC-1] != WALLP && maze[startR][startC-1] != WALLD && maze[startR][startC-1] != WALLH 
                    && maze[startR][startC-1] != START)
                {
                    dirNext = 3;
                    startC--;
                                        
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                if(maze[startR+1][startC] != WALLP && maze[startR+1][startC] != WALLD && maze[startR+1][startC] != WALLH 
                    && maze[startR+1][startC] != START)
                {
                    dirNext = 2;
                    startR++;                    
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC+1] != WALLP && maze[startR][startC+1] != WALLD && maze[startR][startC+1] != WALLH 
                    && maze[startR][startC+1] != START)
                {
                    dirNext = 1;
                    startC++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR-1][startC] != WALLP && maze[startR-1][startC] != WALLD && maze[startR-1][startC] != WALLH 
                    && maze[startR-1][startC] != START)
                {
                    dirNext = 0;
                    startR--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                break;
            case UP:
                if(maze[startR-1][startC] != WALLP && maze[startR-1][startC] != WALLD && maze[startR-1][startC] != WALLH 
                    && maze[startR-1][startC] != START)
                {
                    dirNext = 0;
                    startR--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC-1] != WALLP && maze[startR][startC-1] != WALLD && maze[startR][startC-1] != WALLH 
                    && maze[startR][startC-1] != START)
                {
                    dirNext = 3;
                    startC--;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR+1][startC] != WALLP && maze[startR+1][startC] != WALLD && maze[startR+1][startC] != WALLH 
                    && maze[startR+1][startC] != START)
                {
                    dirNext = 2;
                    startR++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                else if(maze[startR][startC+1] != WALLP && maze[startR][startC+1] != WALLD && maze[startR][startC+1] != WALLH 
                    && maze[startR][startC+1] != START)
                {
                    dirNext = 1;
                    startC++;
                    push(rowStack, startR);
                    push(colStack, startC);
                }
                break;
            default:
                break;
        }

        if(maze[startR][startC] == FINISH)
        {
            maze[startR][startC] = FINISH;
            break;
        }

        direction = dirNext;/*next direction is the direction next*/
    }
    
}
