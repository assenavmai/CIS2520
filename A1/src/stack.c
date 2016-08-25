/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Creating functions for the linked list
 *LAST MODIFICATION: June 6th, 2014
 */

#include "stack.h"

/*Creates an empty stack*/
/*preconditions: createList() from the stack ADT
 *postconditions: An empty stack is created using createList() from the List ADT
*/
Stack * createStack()/*creates a new stack*/
{
    Stack * newStack;
    
    newStack = malloc(sizeof(Stack));

    if(newStack == NULL)
    {
        printf("Failed. Stack not created.\n");
    }
    else
    {
        newStack->list = createList();
        newStack->len = 0;
    }

    return newStack;
}

/*preconditions: An initialized stack is passed in as a parameter
 *postconditions: The memory used is freed, the list is freed using destroy() from List ADT
*/
void destroyStack(Stack * theStack)
{
    destroy(theStack->list);

    theStack->list = NULL;
    theStack->len = 0;
}

/*preconditions: an initialized stack is passed in and the data that will be added to that list
 *postconditions: Calls addToFront() from List ADT and adds a new top to the stack
*/
void push(Stack * theStack, int element)
{   
    Node * add;

    add = addToFront(theStack->list, element);

    theStack->list = add;
    theStack->len++;
}

/*preconditions: an initialized stack gets passed in as the parameter
 *postconditions: Removes the top of the stack, the next element becomes the new top
*/
void pop(Stack * theStack)
{
    Node * rm;

    if(theStack == NULL)
    {
        printf("No top to pop.\n");
    }
   
    rm = removeFromFront(theStack->list);
    theStack->list = rm;
    theStack->len--;
    
}

/*preconditions: an initialized stack gets passed in as the parameter
 *postconditions: the top of the stack is received using getFront() from List ADT and saved to the struct
*/
int peek(Stack * theStack)
{
    int front;
    /*theStack->top = theStack->list;*/
    if(theStack == NULL)
    {
        printf("Stack is Empty");
        return -1;
    }
    front = getFront(theStack->list);

    return front;
}