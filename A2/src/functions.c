/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: General functions used in main
 *LAST MODIFICATION: July 4th, 2014
 */
#include "functions.h"

FILE * openFile(char * input)
{
    FILE * file;/*declare file pointer*/

    file = fopen(input, "r");/*open file*/

    if(file == NULL)/*if file is null, return null*/
    {
        return NULL;
        /*exit(1);*/
    }

    return file;
}

int displayMenu()
{
    char menu[MAX];
    int option;

    do/*get the user input for the menu, keep looping if they give wrong input*/
    {
        /*prompt user to enter choice and get user input*/
        printf("Please choose from one of the following menu options by entering the corresponding number:\n");
        printf("1. Load a directory file\n2. Add a single entry\n3. Print the directory list\n4. Reverse Lookup\n5. Quit\n");
        printf("\nPlease enter your choice now: ");
        fgets(menu, MAX, stdin);
        menu[strlen(menu) - 1] = '\0';

        if(strcmp(menu, "1") == 0)/*if they want to load a file, option = 1*/
        {
            option = 1;
        }
        if(strcmp(menu, "2") == 0)/*fi they want to add a single entry, option = 2*/
        {
            option = 2;
        }
        if(strcmp(menu, "3") == 0)/*if they want to print the hash table, option = 3*/
        {
            option = 3;
        }
        if(strcmp(menu, "4") == 0)/*if they want to do reverse lookup, option = 4*/
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
