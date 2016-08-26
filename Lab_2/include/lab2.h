/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: saving functions
 *LAST MODIFICATION: May 22, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List /*struct used*/
{
    int nodeValue;
    struct List * next;
};
    
typedef struct List Node;

/*Description:
 *Creates an empty list
 *Parameters:
 *none
 *Return:
 *Returns the dummy node which is the head of the list
 */
Node * createList();

/*Description:
 *Adds a node to the front of the list using initNode()
 *Parameters:
 *theList: the linked list
 *toBeAdded: the data going to be entered into the list
 *Return:
 *Returns the new head of the list
 */
Node * addToFront(Node * theList, int toBeAdded);

/*Description:
 *Gets the head of the list
 *Parameters:
 *theList: the linkedlist 
 *Return:
 *Returns the first node (head) in the list
 */
void getFront(Node * theList);

/*Description:
 *Removes the first node in the list
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
Node * removeFromFront(Node * theList);

/*Description:
 *Allocates memory for one single node
 *Parameters:
 *data: the data to be inserted
 *Return:
 *Returns the new node to be put into the linked list
 */
Node * initNode(int data);

/*Description:
 *gets the length of the linked list
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
void getLength(Node * theList);

/*Description:
 *Prints the entire linkedlist
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
void printList(Node *  theList);

/*Description:
 *Destroys linked list: free memory
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
void destroy(Node * theList);

/*Description:
 *Checks if the list is empty
 *Parameters:
 *theList: the linked list
 *Return:
 *returns 1 if it is empty and 0 if not
 */
int isEmpty(Node * theList);
