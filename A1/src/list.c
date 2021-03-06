/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Creating functions for the linked list
 *LAST MODIFICATION: June 6th, 2014
 */
#include "list.h"

/*Creates an empty list*/
/*preconditions: none
 *postconditions: An empty list is created
*/
Node * createList()
{
    Node * theList;

    theList = NULL; /*set head to null*/

    return theList;
}

/*preconditions: an initialized list is passed in and the data that will be added to that list
 *postconditions: A new head of the list is outputted with the remaining nodes
*/
Node * addToFront(Node * theList, int toBeAdded)/*Add notes to the front of current head*/
{
    Node * newNode;
    
    newNode = initNode(toBeAdded);
    
    if(isEmpty(theList) == 1)/*if the list is empty create a new node*/
    {
        theList = newNode;
        theList->next = NULL;
    }
    else/*continuing adding to the front*/
    {
        newNode->next = theList;
        theList = newNode;
    }
    
    return theList;
}

/*preconditions: an initialized list gets passed in as the parameter
 *postconditions: the head of the list is printed out to the terminal
*/
int getFront(Node * theList)/*gets the head of the list*/
{
    Node * temp;

    temp = theList;

    if(isEmpty(temp) == 1)/*if the list is empty print*/
    {
        printf("The stack is empty, no top\n");
        return -1; /*if the list is empty, it is going to print 0 as the front*/
    }
    /*else
    {
        printf("The top of the stack is: %d\n", temp->nodeValue);
    }*/
    return temp->nodeValue;
}

/*preconditions: an initialized list gets passed in as the parameter
 *postconditions: Removes the current head of the list and makes a new head the next element
*/
Node * removeFromFront(Node * theList)/*function to remove the head*/
{
    Node * temp;
    
    temp = theList;

    if(isEmpty(theList) == 1)/*if the list is empty do not remove anything*/
    {
        printf("The stack is empty, nothing to remove from the top.\n");
    }
    else /*remove the head and make a new head*/
    {
        temp = theList->next;
    }

    return temp;
}

/*preconditions: none
 *postconditions: a node is created that will be inserted into the list
*/
Node * initNode(int data) /*create single node to hold data*/
{
    Node * newNode = malloc(sizeof(Node) *1);/*allocate memory*/

    newNode->nodeValue = data;/*set the data into the struct*/
    newNode->next = NULL;

    return newNode;
}

/*preconditions: An initialized fraction is passed in as a parameter
 *postconditions: The amount of nodes is outputted 
*/
void getLength(Node * theList)/*get amount of nodes in list*/
{
    Node * temp;
    int counter;

    temp = theList;

    if(isEmpty(temp) == 1) /*if the list is empty it will print 0*/
    {
        printf("List is empty, getLength().\n");
    }

    while(temp != NULL)
    {
        temp = temp->next;
        counter++; /*increment when get nodes*/
    }
    
    printf("The length of the list is: %d\n", counter);
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The entire list is printed
*/
void printList(Node *  theList)/*prints entire list*/
{
    if(isEmpty(theList) == 1)/*won't print anything if the list is empty*/
    {
        printf("Stack is empty, nothing to print.\n");
    }
    else
    {
        printf("The Stack: ");
    }
    while(theList != NULL)/*while the list is not null print out the nodes*/
    {
        printf ("%d ", theList->nodeValue);
        theList = theList->next;
    }
    printf("\n");
}

/*preconditions: An initialized List is passed in as a parameter
 *postconditions: If the list is empty, returns true else returns false
*/
int isEmpty(Node * theList)/*checks if the list is empty*/
{
    if(theList == NULL)/*if it is empty return true(1)*/
    {
        return 1;
    }
    
    return 0;/*else return false (0)*/
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The memory used is freed
*/
void destroy(Node * theList)/*to free memory*/
{
    Node * temp;

    if(isEmpty(theList) == 1)/*if list is empty there is nothing to free*/
    {
        printf("Stack is empty, nothing to destroy.\n");
    }

    while(theList != NULL)/*free the memory*/
    {
        temp = theList;
        theList = temp->next;
        free(theList);
    } 
}
