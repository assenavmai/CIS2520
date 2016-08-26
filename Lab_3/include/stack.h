/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: saving functions
 *LAST MODIFICATION: May 29, 2014
 */
#include "list.h"

struct StackType /*struct used*/
{
    Node * list;
    int len;
};
    
typedef struct StackType Stack;

/*Description:
 *Creates an empty stack
 *Parameters:
 *none
 *Return:
 *Returns a dummy node from linked list and creates empty stack
 */
Stack * createStack();

/*Description:
 *Destroys linked list: free memory and releases memory from the stack
 *Parameters:
 *theStack: the stack
 *Return:
 *No return value
 */
void destroyStack(Stack * theStack);

/*Description:
 *Adds an element to the top of the stack using addToFront() from List ADT
 *Parameters:
 *theStack: the stack
 *element: the data going to be entered into the stack
 *Return:
 *No return value
 */
void push(Stack * theStack, int element);

/*Description:
 *Removes the top of the stack
 *Parameters:
 *theStack: the stack
 *Return:
 *No return value
 */
void pop(Stack * theStack);

/*Description:
 *Gets the top of the stack
 *Parameters:
 *theStack: the stack
 *Return:
 *No return value
 */
void peek(Stack * theStack);

