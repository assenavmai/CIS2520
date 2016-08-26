/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: test program
 *LAST MODIFICATION: May 29, 2014
 */

 #include "stack.h"

int main(void)
{
    int arr[3] = {1,2,3}; /*array of test data*/
    int array[7] = {100,200,300,1000,2000,10000,10000000};
    int arrayThree[1];
    int arrayFour[5] = {-2568,-898,1245,-54964,-556};
    Stack * stack, *stackTwo, *stackThree, *stackFour;
    int i;

    /*normal array*/
    /*Checks for common values, small array. Tests when the stack is empty - all of the functions.
    */
    printf("    test case one\n");
    
    stack = createStack();
    pop(stack);
    peek(stack);
    printList(stack->list);
    destroyStack(stack);

    for(i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) 
    {
        push(stack, arr[i]);
        printList(stack->list);
    }
    printf("The length of the stack is: %d\n", stack->len);
    
    pop(stack);
    printList(stack->list);
    
    printf("The length of the stack is: %d\n", stack->len);
    peek(stack);
    printList(stack->list);
    destroyStack(stack);

    /*testing big numbers*/
    /*Testing big numbers, seeing how the stack will react such as lack of memory*/
    /*since using linked list implementation for the stack, initNode() will always create enough memory*/
    printf("\n    test case two\n");
    stackTwo = createStack();

    for(i = 0; i < sizeof(array)/sizeof(array[i]); i++) 
    {
        push(stackTwo, array[i]);
        printList(stackTwo->list);
    }
    
    printf("The length of the stack is: %d\n", stackTwo->len);
    
    pop(stackTwo);
    printList(stackTwo->list);
    
    printf("The length of the stack is: %d\n", stackTwo->len);
    peek(stackTwo);
    destroyStack(stackTwo);

    /*empty array size of 1*/
    /*tests for when the array is empty, sees the garbage values that output, but then reads it as an empty stack
    afterwards*/
    printf("\n    test case three\n");
    stackThree = createStack();

    for(i = 0; i < sizeof(arrayThree)/sizeof(arrayThree[i]); i++) 
    {
        push(stackThree, arrayThree[i]);
        printList(stackThree->list);
    }
    printf("The length of the stack is: %d\n", stackThree->len);
    
    pop(stackThree);
    printList(stackThree->list);
    
    printf("The length of the stack is: %d\n", stackThree->len);
    peek(stackThree);
    destroyStack(stackThree);

    /*Negative values*/
    /*Testing if the negative values will register correctly*/
    printf("\n    test case four\n");
    stackFour = createStack();

    for(i = 0; i < sizeof(arrayFour)/sizeof(arrayFour[i]); i++) 
    {
        push(stackFour, arrayFour[i]);
        printList(stackFour->list);
    }
    
    printf("The length of the stack is: %d\n", stackFour->len);
    
    pop(stackFour);
    printList(stackFour->list);
    
    printf("The length of the stack is: %d\n", stackFour->len);
    peek(stackFour);
    destroyStack(stackFour);
    
    printList(stackFour->list);


    return 0;
}