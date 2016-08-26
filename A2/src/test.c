/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: main function
 *LAST MODIFICATION: July 4th, 2014
 */
#include "hash.h"
#include "functions.h"

int main(int argc, char const *argv[])
{
    /*Initializing variables*/
    FILE * f;
    int size;
    int menuOption;
    int amountOfNodes;
    char loadFile[MAX];
    char reverse[MAX];
    char line[MAXSIZE];
    char first[MAXSIZE];
    char last[MAXSIZE];
    char number[MAXSIZE];
    Record * look;
    Record * recordPtr;
    Record * head;
    HT * myTable = NULL;

    menuOption = displayMenu(); /* call the menuOption function*/

    do/*keep looping until the user quits*/
    {
        switch(menuOption)
        {
            case 1:
                printf("\nPlease enter the file directory and filename now: ");/*fopen the file they entered, just type in the filename*/
                fgets(loadFile, MAX, stdin);
                loadFile[strlen(loadFile) - 1] = '\0';/*replace '\n' with '\0'*/
                f = openFile(loadFile);
                /* printf("\n");*/

                if(f == NULL)/*if they entered an invalid name*/
                {
                    fprintf(stderr, "Error: Invalid filename.\n\n");
                }
                else
                {
                        head = createList();
                        head = malloc(sizeof(Record));/*malloc for the list*/

                        fgets(line, sizeof(line), f);/*get the head of the list(first line in text file)*/
                        line[strlen(line) - 1] = '\0';
                        head = storeDirectory(line);/*parse input*/
                 
                        while(fgets(line, sizeof(line), f) != NULL)/*read the rest of the file*/
                        {
                            line[strlen(line) - 1] = '\0';/*remove newline on each line*/
                            recordPtr = storeDirectory(line);/*parse input*/
                            head = addToFront(head, recordPtr);/*add to front of list*/
                            amountOfNodes = count(recordPtr);/*count the amount of nodes*/
                        }

                        size = calculateTableSize(amountOfNodes);/*calculate 2/3 size of tabke*/
                        myTable = create(size);/*create table*/
                        fillTable(myTable, head);/*fill table with linked list*/

                        printf("SUCCESS: Your file has been successfully loaded.\n\n");
                }
                menuOption = displayMenu();/*call the menu again*/
                break;
            case 2:

                if(myTable == NULL || head == NULL)/*if the table or list is null do not process*/
                {
                    printf("\nThere is no directory in storage. Please try loading a file.\n\n");
                }

                if(myTable != NULL && head != NULL)
                {
                    printf("You chose to enter a single entry.\n");
                    /*Get the persons information from user*/
                    printf("Please enter a first name: ");
                    fgets(first, MAXSIZE, stdin);
                    first[strlen(first) - 1] = '\0';

                    printf("Please enter a last name: ");
                    fgets(last, MAXSIZE, stdin);
                    last[strlen(last) - 1] = '\0';

                    printf("Please enter a 10 digit phone number: ");
                    fgets(number, MAXSIZE, stdin);
                    number[strlen(number) - 1] = '\0';

                    recordPtr = createRecord(first, last, number);
                    head = addToFront(head, recordPtr);
                    amountOfNodes = count(recordPtr);

                    size = calculateTableSize(amountOfNodes);
                    myTable = create(size);
                    fillTable(myTable, head);
                }

                menuOption = displayMenu();
                break;
            case 3:
                if(myTable == NULL) /*if they did not load a file*/
                {
                    printf("\nFAILURE: You did not load a file or your file is empty.\nPlease load a file first.\n\n");
                }
                else/*else print the table*/
                {
                    printf("\nSUCCESS: Your directory.\n");
                    printTable(myTable);
                    printf("\n\n");
                }
                menuOption = displayMenu(); /*display menu again*/
                break;
            case 4:
                if(myTable == NULL || head == NULL)/*if the table or list is null do not process*/
                {
                    printf("\nThere is no directory in storage. Please try loading a file.\n\n");
                }
                else
                {
                    printf("\nYou chose to do a reverse lookup\nPlease enter the 10 digit phone number now: ");
                    fgets(reverse, MAX, stdin);/*get their input*/
                    reverse[strlen(reverse) - 1] = '\0';

                    look = lookup(myTable, reverse);/*search the table*/

                    if(look != NULL)/*if a person is found, print their name*/
                    {
                        printf("\nPerson Found\n%s %s\n\n", look->firstName, look->lastName);
                    }
                    else/*else, tell them the number they entered does not exist*/
                    {
                        printf("\n\nThe number you have entered does not correspond to anyone in the directory.\n\n");
                    }
                }

                menuOption = displayMenu();/*display the menu again*/
                break;
            default:
                break;
        }

    }while(menuOption != 5);
    printf("\nThanks for using Reverse Lookup. Goodbye.\n");

    destroyTable(myTable);

    return 0;
}
void openDirectories(const char * dir_name)
{
    DIR * pDir;
    char * file, * dir;
    struct dirent * pDirent;
    const char * d_name;
    int len;
    char path[200];

    file = malloc(sizeof(char) * 256);
    dir = malloc(sizeof(char) * 256);

    /* Open the directory specified by "dir_name". */
    pDir = opendir(dir_name);

    /* Check it was opened. */
    if (pDir == NULL) 
    {
        fprintf (stderr, "Cannot open directory '%s': %s\n", dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }

    while ((pDirent = readdir(pDir)) != NULL) 
    {        
        if (pDirent == NULL) 
        {
            /* There are no more entries in this directory, so break
               out of the while loop. */
            break;
        }
        
        d_name = pDirent->d_name;

        /* Print the name of the file and directory. */
        printf ("ll%s/%s\n", dir_name, d_name);
        
        /*if it is a file, strcpy it*/
        if(pDirent->d_type == DT_REG)
        {
            strcat(file, dir_name);
            strcat(file, "/");
            strcat(file, d_name);
        }

        /* See if "pDirent" is a subdirectory of "d". */
        if (pDirent->d_type == DT_DIR) 
        {
            /*if it is a parent or child directory, skip over it*/
            if (strcmp (d_name, "..") == 0 && strcmp (d_name, ".") == 0) 
            {
                continue;
            }
            
            /*if it is not a parent or child directory*/
            if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) 
            {
                
                len = snprintf(path, 200, "%s/%s", dir_name, d_name);

                if (len >= 200) 
                {
                    fprintf (stderr, "Path length has got too long.\n");
                    exit (1);
                }
                /* Recursively call with the new path. */
                openDirectories(path);
            }
        }
    }

    strcpy(dir, dir_name);

    /*close the directory*/
    if (closedir (pDir)) 
    {
        fprintf (stderr, "Could not close '%s': %s\n", dir_name, strerror (errno));
        exit (1);
    }

    printf("\n\n[%s]\n", file);
}
/*DIR * pDir;
    struct dirent * pDirent;
    char parent[200] = "OpenThis";
    char path[200];
    char * file;
    char * dir;

    file = malloc(sizeof(char) * 256);
    dir = malloc(sizeof(char) * 256);

    pDir = opendir(parent);

    if(pDir == NULL)
    {
        printf("Cannot open directory\n");
    }
    else
    {
        printf("Directory opened successfully\n");
    }

    getcwd(path, 200);
    strcat(path, "/");
    strcat(path, parent);

    while((pDirent = readdir(pDir)) != NULL)
    {
        if(strcmp(pDirent->d_name, ".") == 0 || strcmp(pDirent->d_name, "..") == 0)
        {
            continue;
        }
        if(pDirent->d_type == 8)
        {
            strcat(file, pDirent->d_name);
            strcat(file, "\n");
        }
        else if(pDirent->d_type == 4)
        {
            strcpy(dir, pDirent->d_name);

        }
        printf("[%s]\n", pDirent->d_name);
    }

    printf("In: %s\n", path);
    printf("%s", file);
    printf("%s\n", dir);

    closedir(pDir);

    free(dir);
    free(file);*/