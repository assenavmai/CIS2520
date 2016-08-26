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

int main(int argc, char const *argv[])
{
    /*Initializing variables*/
    DIR * pDir;
    struct dirent * pDirent;
    char parent[200] = "TestFolder";
    char path[200];
    char * file;
    char * dir;

    file = malloc(sizeof(char) * 256);/*malloc memory*/
    dir = malloc(sizeof(char) * 256);

    pDir = opendir(parent);/*open the directory*/

    if(pDir == NULL)
    {
        printf("Cannot open directory\n");
    }
    else
    {
        printf("Directory opened successfully\n");
    }

    /*get the current path*/
    getcwd(path, 200);
    strcat(path, "/");
    strcat(path, parent);

    while((pDirent = readdir(pDir)) != NULL)/*read the directory*/
    {
        if(strcmp(pDirent->d_name, ".") == 0 || strcmp(pDirent->d_name, "..") == 0)/*if its . or ..  skip it*/
        {
            continue;
        }
        if(pDirent->d_type == DT_REG)/*if its a file strcpy into pointer*/
        {
            strcat(file, pDirent->d_name);
            strcat(file, "\n");
        }
        else if(pDirent->d_type == DT_DIR)/*if its a directory strcpy into pointer*/
        {
            strcpy(dir, pDirent->d_name);

        }
        printf("[%s]\n", pDirent->d_name);/*print file name*/
    }

    printf("In: %s\n", path);/*current path*/
    printf("In: %s\n", dir);
    

    /*delete file*/
    printf("Deleting deleteThis.c\n");
    chdir(path);/*change directory*/
    remove("deleteThis.c");

    /*rename file*/
    printf("Rename rename.c\n");
    chdir(path);
    rename("renameThis.c", "newName.c");

    closedir(pDir);/*close directory*/

    free(dir);
    free(file);

    return 0;
}