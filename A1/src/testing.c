/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: test program
 *LAST MODIFICATION: June 6TH, 2014
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
    int top;

    /*normal array*/
    /*Checks for common values, small array. Tests when the stack is empty - all of the functions.
    */
    printf("    test case one: TEST COMMON VALUES SMALL ARRAY. BEGINNING TESTS FOR EMPTY STACK - ALL FUNCTIONS\n");
    
    stack = createStack();
    pop(stack);
    top = peek(stack);
    printf("The top of the stack is (returns -1 if the stack is empty): %d\n", top);
    printList(stack->list);
    destroyStack(stack);

    for(i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) 
    {
        push(stack, arr[i]);
        printList(stack->list);
    }
    printf("The length of the stack is: %d\n", stack->len);
    
    printf("\nPOPPED: ");
    pop(stack);
    printList(stack->list);
    
    printf("The length of the stack is: %d\n", stack->len);
    top = peek(stack);
    printf("The top of the stack is (returns -1 if the stack is empty): %d\n", top);
    printList(stack->list);
    destroyStack(stack);

    /*testing big numbers*/
    /*Testing big numbers, seeing how the stack will react such as lack of memory*/
    /*since using linked list implementation for the stack, initNode() will always create enough memory*/
    printf("\n    test case two: TESTING BIG NUMBERS - LACK OF MEMORY - ALL FUNCTIONS\n");
    stackTwo = createStack();

    for(i = 0; i < sizeof(array)/sizeof(array[i]); i++) 
    {
        push(stackTwo, array[i]);
        printList(stackTwo->list);
    }
    
    printf("The length of the stack is: %d\n", stackTwo->len);
    
    printf("\nPOPPED: ");
    pop(stackTwo);
    printList(stackTwo->list);
    
    printf("The length of the stack is: %d\n", stackTwo->len);
    top = peek(stackTwo);
    printf("The top of the stack is (returns -1 if the stack is empty): %d\n", top);
    destroyStack(stackTwo);

    /*empty array size of 1*/
    /*tests for when the array is empty, sees the garbage values that output, but then reads it as an empty stack
    afterwards*/
    printf("\n    test case three: TESTING EMPTY ARRAY - SOME FUNCTIONS CANNOT USE THIS TEST - SEGFAULT - GARBAGE VALUES OUTPUTTED\n");
    stackThree = createStack();

    for(i = 0; i < sizeof(arrayThree)/sizeof(arrayThree[i]); i++) 
    {
        push(stackThree, arrayThree[i]);
        printList(stackThree->list);
    }
    printf("The length of the stack is: %d\n", stackThree->len);
    
    printf("\nPOPPED: ");
    pop(stackThree);
    printList(stackThree->list);
    
    printf("The length of the stack is: %d\n", stackThree->len);
    top = peek(stackThree);
    printf("The top of the stack is (returns -1 if the stack is empty): %d\n", top);
    destroyStack(stackThree);

    /*Negative values*/
    /*Testing if the negative values will register correctly*/
    printf("\n    test case four: TESTING NEGATIVE VALUES - ALL FUNCTIONS - PRINTING AFTER DESTROY TO SEE IF IT ACTUALLY WORKS\n");
    stackFour = createStack();

    for(i = 0; i < sizeof(arrayFour)/sizeof(arrayFour[i]); i++) 
    {
        push(stackFour, arrayFour[i]);
        printList(stackFour->list);
    }
    
    printf("The length of the stack is: %d\n", stackFour->len);
    
    printf("\nPOPPED: ");
    pop(stackFour);
    printList(stackFour->list);
    
    printf("The length of the stack is: %d\n", stackFour->len);
    top = peek(stackFour);
    printf("The top of the stack is (returns -1 if the stack is empty): %d\n", top);
    destroyStack(stackFour);
    
    printList(stackFour->list);


    return 0;
}