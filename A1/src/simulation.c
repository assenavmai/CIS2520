
/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: main program to run functions
 *LAST MODIFICATION: June 6th, 2014
 */
#include "maze.h"

int main(int argc, char const *argv[])
{
    /*Initializing the variables*/
    FILE * f;
    char line[BUFFERSIZE];
    int i, j, nRows, len, startR, startC;
    char ** maze = NULL;
    Stack * rowStack, * colStack;
    
    /*Declaring variables*/
    i = 0;
    j = 0;
    nRows = 0;

    /*opening the file and mallocing for the maze*/
    f = openFile(argc, argv); 
    maze = mallocMaze(maze);

    /*Creating stacks for the rows and columns*/
    rowStack = createStack();
    colStack = createStack();

    /*if the file is NULL, exit else read from the file and store into the char** array*/
    if(f == NULL)
    {
        fprintf(stderr, "Error opening file. Exiting\n");
        exit(1);
    }
    else
    {

        while(fgets(line, sizeof(line), f) != NULL)
        {
            for(j = 0; j < strlen(line) + 1; j++)
            {
                maze[i][j] =  line[j];

                if(maze[i][j] == START)
                {
                    push(rowStack, i);
                    push(colStack, j);

                    startR = i;
                    startC = j;
                }
            }
            
            maze[i][j] = '\0';
            i++;
            nRows++;
        }
        fclose(f);
    }
    
    len = strlen(line);



    findStart(maze, nRows, len, rowStack, colStack, startR, startC);

    printMaze(maze, nRows, len, rowStack, colStack);

    return 0;
}