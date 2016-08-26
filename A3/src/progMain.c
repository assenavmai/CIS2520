/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: MENU
 *LAST MODIFICATION: August 1st, 2014
 */
#include "functions.h"

int main(int argc, char const *argv[])
{
    /*Initialize variables*/
    Manager * toDelete, * toRename, * toMove;
    Tree * myTree;
    char * pathFound;
    int menuOption;
    char path[BUFFERSIZE];
    char rm[BUFFERSIZE];
    char oldName[BUFFERSIZE];
    char newName[BUFFERSIZE];
    char search[BUFFERSIZE];
    char move[BUFFERSIZE];
    char * oldDir;
    char * newDir;

    /*malloc memory*/
    newDir = malloc(sizeof(char) * BUFFERSIZE);
    oldDir = malloc(sizeof(char) * BUFFERSIZE);
    myTree = createTree(&compare, &destroy);

    if(argc != 2)/*if the second arguement is not entered exit*/
    {
        printf("Usage: Enter a pathname.\n");
        exit(1);
    }

    /*open directores*/
    openDirectories(myTree, argv[1]);
    /*printInOrder(myTree->root, &printNode);
    prettyPreOrder(myTree->root, 0, &printNode);*/

    menuOption = displayMenu();/*call to display the menu*/

    do
    {
        switch(menuOption)
        {
            /*if it returns 1 the user want to search*/
            case 1:
                printf("You chose to search for a path via filename.\n");
                printf("Please enter the filename you want to find now: ");
                getInput(search);/*get the file they want to find*/
                pathFound = getPath(myTree->root, search);/*search for the file*/

                if(pathFound == NULL)/*if it is not found, it is not in the directory*/
                {
                    printf("\nSorry, the filename you entered is not in any of the directories\n\n");
                }
                else/*if not it is found successful*/
                {
                    printf("\nSearch successful.\n");
                    printf("It is located in: %s\n\n", pathFound);
                }
                menuOption = displayMenu();/*display the menu again*/
                break;
            case 2:/*user chose to delete a file*/
                printf("\nYou chose to delete a file.\n");
                printf("Please enter the file name you would like to delete: ");
                getInput(rm);/*get user input*/
                pathFound = getPath(myTree->root, rm);/*search for the file*/

                if(pathFound == NULL)/*if not found, tell them it wasn't found*/
                {
                    printf("\nSorry, the filename you entered is not in any of the directories\n\n");
                }
                else
                {
                    toDelete = createNode(rm, pathFound);/*create a node to delete*/
                    deleteFile(pathFound, rm);/*delete the node from the directory*/
                    removeFromTree(myTree, toDelete);/*remove node from tree*/
                    printf("Delete successful\n\n");
                }
                menuOption = displayMenu();/*call the menu*/
                break;
            case 3:/*user chose to rename file*/
                printf("\nYou chose to rename a file.\n");
                printf("Please enter the filename that you would like to rename: ");
                getInput(oldName);/*get user input of the file to rename*/
                printf("Please enter the new filename you would like: ");
                getInput(newName);/*get user input to give the new file name*/
                
                pathFound = getPath(myTree->root, rm);/*fine the path*/

                if(pathFound == NULL)/*if the path isnt found tell the user*/
                {
                    printf("\nSorry, the filename you entered is not in any of the directories\n\n");
                }
                else
                {
                    renameFile(pathFound, oldName, newName);/*rename the file in the directory*/
                    
                    /*rename the file in the tree*/
                    toRename = createNode(oldName, pathFound);
                    removeFromTree(myTree, toRename);
                    toRename = createNode(newName, pathFound);
                    addToTree(myTree, toRename);
                    printf("Rename successul\n");
                }
                menuOption = displayMenu();/*call the menu*/
                break;
            case 4:/*if the user wants to move a file*/
                printf("\nYou chose to move a file to a new directory\n");/*get the file and path they want to move to*/
                printf("Please enter the file you wish to move: ");
                getInput(move);
                printf("Please enter the directory you want to move %s to: ", move);
                getInput(path);

                pathFound = getPath(myTree->root, move);

                if(pathFound == NULL)
                {
                    printf("\nSorry, the filename you entered is not in any of the directories\n");
                }
                else
                {
                    strcat(oldDir, pathFound);/*get the path of the old directory*/
                    strcat(oldDir, "/");
                    strcat(oldDir, move);

                    strcat(newDir, path);/*get the path of the new directory*/
                    strcat(newDir, "/");
                    strcat(newDir, move);

                    rename(oldDir, newDir);/*move the file in the directory*/
                    deleteFile(oldDir, move);/*delete the file in the old directory*/
                    
                    /*update the tree*/
                    toDelete = createNode(move, pathFound);
                    removeFromTree(myTree, toDelete);
                    toMove = createNode(move, path);
                    addToTree(myTree, toMove);
                    printf("Move successful\n");
                }
                menuOption = displayMenu();/*call the menu*/
                break;
            default:
                break;
        }

    }while(menuOption != 5);/*if user puts in 5, quit*/
    printf("\nThanks for using Reverse Lookup. Goodbye.\n");

    destroyTree(myTree);

    return 0;
}