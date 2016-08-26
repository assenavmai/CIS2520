#include "treeInterface.h"
#include "structInfo.h"

int main(void)
{
    /*Initializing variables*/
    Tree * nTree, *rTree;
    Restaurant * firstLine, * myInfo;
    FILE * f;
    char line[200];

    /*open the file and read it*/
    f = fopen("data.txt", "r");

    /*creating the trees*/
    nTree = createBinTree(&compareName, &destroyDataNode);
    rTree = createBinTree(&compareRating, &destroyDataNode);

    /*read from file and store into both trees*/
    fgets(line, sizeof(line), f);
    firstLine = storeDirectory(line);
    addToTree(nTree, firstLine);
    addToTree(rTree, firstLine);

    while(fgets(line, sizeof(line), f) != NULL)
    {
     	myInfo = storeDirectory(line);
        addToTree(nTree, myInfo);
        addToTree(rTree, myInfo);
    }

    /*Print restaurant information in the order of their names*/
    printf("----------------------Name Order-----------------------\n");
    printInOrder(nTree, &printNode);
    printf("\n");

    /*Print restaurant information in order of their ratings*/
    printf("----------------------Rating Order-----------------------\n");
    printInOrder(rTree, &printNode);

    printf("\n--------------Name tree-------------------------\n");
    printOrder(nTree);

    printf("\n--------------Rating tree-------------------------\n");
    printOrder(rTree);

    destroyDataNode(nTree);
    destroyDataNode(rTree);

    return 0;
}

