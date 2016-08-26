/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: AVL TESTING
 *LAST MODIFICATION: August 1st, 2014
 */
#include "bst.h"

int main(int argc, char const *argv[])
{
    /*Initializing variables*/
    FILE * f;
    Tree * myTree;
    Manager * firstLine, * myInfo;
    int found;
    Manager * findThis, * removeNode;
    char line[200];

    f = fopen("testing.txt", "r");/*open file to test*/

    if(f == NULL)/*if file is null, exit*/
    {
        printf("Could not open file.\n");
        exit(1);
    }

    /*Creating the binary tree*/
    myTree = createTree(&compare, &destroy);
    printf("\nBinary tree created....createTree() successful\n");

    /*reading the file and adding it to the tree*/
    fgets(line, sizeof(line), f);
    line[strlen(line) - 1] = '\0';
    firstLine = storeDirectory(line);
    addToTree(myTree, firstLine);

    while(fgets(line, sizeof(line), f) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        myInfo = storeDirectory(line);
        addToTree(myTree, myInfo);
    }
    printf("\ncreated Manager * type nodes\n");
    printf("\nadded Manager * type to the binary tree, successful\n");

    /*print the tree in order*/
    printf("Printing binary tree in order of filename: \n");
    printInOrder(myTree->root, &printNode);

    /*search the binary tree...only compares filenames not paths*/
    /*filename is located in the tree*/
    printf("Searching to see if hello.txt at path /home is in the tree\n");
    findThis = createNode("hello.txt", "/home");
    found = isInTree(myTree, findThis);

    /*if it is found, print it. else tell the user it is not in the tree*/
    if(found == 1)
    {
        printf("Found in the tree %s/%s\n", findThis->filepath, findThis->filename);
    }
    else
    {
        printf("%s/%s not found in the tree\n", findThis->filepath, findThis->filename);
    }

    /*searching a file name not located in the tree*/
    printf("Searching to see if hello.txt at path /no is in the tree\n");
    findThis = createNode("h.txt", "/no");
    found = isInTree(myTree, findThis);

    /*if it is found, print it. else tell the user it is not in the tree*/
    if(found == 1)
    {
        printf("Found in the tree %s/%s\n", findThis->filepath, findThis->filename);
    }
    else
    {
        printf("%s/%s not found in the tree\n", findThis->filepath, findThis->filename);
    }

    /*deleting a single node in the tree*/
    printf("Deleting: /Data/WhiteVanessaA2/src/hash.c");
    removeNode = createNode("hash.c", "/Data/WhiteVanessaA2/src");
    removeFromTree(myTree, removeNode);

    printf("\nEnd of test\n\n");

    destroyTree(myTree);

    return 0;
}