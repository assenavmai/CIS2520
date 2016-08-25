#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 2048

int main(void)
{
    FILE * f;
    char line[BUFFERSIZE];
    char map[BUFFERSIZE][BUFFERSIZE];
    int i, j, nRows;
    
    i = 0;
    j = 0;
    nRows = 0;
 /*   row = 31;
    col = 46;*/

    f = fopen("maze.txt", "r");

    if(f != NULL)
    {
        i = 0;

        while(fgets(line, sizeof(line), f) != NULL)
        {
            for(j = 0; j < strlen(line); j++)
            {
                map[i][j] =  line[j];
            }
            
            map[i][j] = '\0';
            i++;
            nRows++;
        }
        fclose(f);

    }
    printf("%d\n", nRows);
    for ( i = 0; i < nRows; i++ )
    {
        for ( j = 0; j < strlen(line); j++ )
        {
            fputc(map[i][j],stdout);
        }
            
        fputc('\n', stdout);
    }

   for(i = 0; i < nRows; i++)
   {
        for(j = 0; j < strlen(line); j++)
        {
            if(map[i][j] == 'S')
            {
                printf("Found Start %d %d\n", i, j);
            }
        }
   }


    return 0;
}