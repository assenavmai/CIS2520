/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: MENU
 *LAST MODIFICATION: August 1st, 2014
 */
#include "functions.h"

/*preconditions: initialized tree and directory passed in*/
/*postconditions: file names and directories stored into struct*/
void openDirectories(Tree * theTree, const char * dir_name)
{
    DIR * pDir;
    char * file, * dir;
    Manager * fileMan;
    struct dirent * pDirent;
    const char * d_name;
    int path_length;
    char path[BUFFERSIZE];

    file = malloc(sizeof(char) * BUFFERSIZE);
    dir = malloc(sizeof(char) * BUFFERSIZE);

    /* Open the directory specified by "dir_name". */
    pDir = opendir(dir_name);

    /* Check it was opened. */
    if (pDir == NULL) 
    {
        fprintf (stderr, "Cannot open directory '%s': %s\n", dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }

    /*while reading the directory*/
    while ((pDirent = readdir(pDir)) != NULL) 
    {        
        if (pDirent == NULL) 
        {
            break;
        }

        d_name = pDirent->d_name;

        /*printf ("%s    %s\n", dir_name, d_name);*/
        
        if(pDirent->d_type == DT_REG)
        {
            strcpy(file, d_name);
        }

        if (pDirent->d_type == DT_DIR) /*if the type is a directory*/
        {
            if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) 
            {
                if (strcmp (d_name, "..") == 0 || strcmp (d_name, ".") == 0) /*skip the .. and . files*/
                {
                    continue;
                }
                path_length = snprintf(path, BUFFERSIZE, "%s/%s", dir_name, d_name);/*append the path*/

                if (path_length >= BUFFERSIZE) 
                {
                    fprintf (stderr, "Too long of a path\n");
                    exit (1);
                }
                
            }
        }
    }
    strcpy(dir, dir_name);
    fileMan = createNode(file, dir);
    addToTree(theTree, fileMan);
    
    if (closedir (pDir)) /*if could not close the directory*/
    {
        fprintf (stderr, "Could not close '%s': %s\n", dir_name, strerror (errno));
        exit (1);
    }
}

/*preconditions: initialized tree and directory passed in*/
/*postconditions: file names and directories stored into struct*/
void getDirectory(Tree * theTree, const char * parent)
{
    DIR * pDir;
    struct dirent * pDirent;
    char path[200];
    char * file;
    char * dir;
    Manager * fileMan;

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
            strcpy(file, pDirent->d_name);
        }
        else if(pDirent->d_type == DT_DIR)/*if its a directory strcpy into pointer*/
        {
            strcpy(dir, pDirent->d_name);

        }
        fileMan = createNode(pDirent->d_name, path);
        addToTree(theTree, fileMan);
    }

}

/*preconditions: user input is passed in*/
/*postconditon: removes new line character*/
void getInput(char * input)
{
    fgets(input, BUFFERSIZE, stdin);
    input[strlen(input) - 1] = '\0';
}

/*preconditions: none*/
/*postconditions: a menu is displayed*/
int displayMenu()
{
    char menu[BUFFERSIZE];
    int option;

    do/*get the user input for the menu, keep looping if they give wrong input*/
    {
        /*prompt user to enter choice and get user input*/
        printf("Welcome to the File Manager!\n");
        printf("Please choose from one of the following menu options by entering the corresponding number:\n");
        printf("1. Search for a file\n2. Delete a file\n3. Rename a file\n4. Move a file\n5. Quit\n");
        printf("\nPlease enter your choice now: ");
        getInput(menu);

        if(strcmp(menu, "1") == 0)/*if they want to search for a file, option = 1*/
        {
            option = 1;
        }
        if(strcmp(menu, "2") == 0)/*fi they want to delete a file, option = 2*/
        {
            option = 2;
        }
        if(strcmp(menu, "3") == 0)/*if they want to rename a file, option = 3*/
        {
            option = 3;
        }
        if(strcmp(menu, "4") == 0)/*if they want to move a file, option = 4*/
        {
            option = 4;
        }
        if(strcmp(menu, "5") == 0)/*if they want to quitm option = 5*/
        {
            option = 5;
        }
        /*if they entered an invalid menu choice, tell them to try again*/
        if((strcmp(menu, "1") != 0) && (strcmp(menu, "2") != 0) && (strcmp(menu, "3") != 0) && (strcmp(menu, "4") != 0) && (strcmp(menu, "5") != 0))
        {
            printf("\n\nSorry, the choice you entered is not valid. Please try again\n\n");
        }
    }while((strcmp(menu, "1") != 0 && strcmp(menu, "2") != 0 && strcmp(menu, "3") != 0 && strcmp(menu, "4") != 0) && strcmp(menu, "5") != 0);

    return option;
}

/*preconditions: a pathname, old filename and a new filename is passed in from user input*/
/*postconditions: the file is renamed in the directory*/
void renameFile(char * pathname, char * oldFilename, char * newFilename)
{
    chdir(pathname);
    rename(oldFilename, newFilename);
}

/*preconditions: a pathname and the file to delete is passed in*/
/*postconditions: file is deleted*/
void deleteFile(char * pathname, char * toDelete)
{
    chdir(pathname);
    remove(toDelete);
}
