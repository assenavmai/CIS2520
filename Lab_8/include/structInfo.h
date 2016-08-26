#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeInterface.h"

struct data{

    char * rName;
    char * foodType;
    int rating;
};

typedef struct data Restaurant;

/*Creates a new node with information; stores info into struct
 *@param name: restaurant name
 *@param food: food type
 *@param rate: rating
 *Returns new struct with the node in it
 */
Restaurant * createNode(char * name, char * food, int rate);

/*Compares 2 names in the struct so it can sort it
 *@param data1: first data item
 *@param data2: last data item
 *Returns 1 if data 1 is bigger, -1 if data 1 is smaller and 0 if they are equal
 */
int compareName(void * data1, void * data2);

/*Compares 2 ratings in the struct so it can sort it
 *@param data1: first data item
 *@param data2: last data item
 *Returns 1 if data 1 is bigger, -1 if data 1 is smaller and 0 if they are equal
 */
int compareRating(void * data1, void * data2);

/*Prints the node 
 *@param parameter: data to be printed
 *no return value
 */
void printNode(void * parameter);

/*Destroys Tree
 *@param node: tree to be destroyed
 *no return value
 */
void destroyDataNode(void * node);

/*Takes a line from the file and parses it then stores it into the struct
 *@param line: the line of information from the file
 *returns the new node in the list 
 */
Restaurant * storeDirectory(char * line);

void printOrder(Tree * theTree);

TreeNode * findMin(TreeNode * node)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(node->left == NULL)
    {
        return node;
    }
    else
    {
        return findMin(node->left);
    }
}