/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Test the functions in lab2.c
 *LAST MODIFICATION: May 23, 2014
 */
#include "list.h"

int main(void)
{
    int arr[3] = {1,2,3}; /*array of test data*/
    int array[7] = {100,200,300,1000,2000,10000,10000000};
    int arrayThree[1];
    int arrayFour[5] = {-2568,-898,1245,-54964,-556};
    Node * list, *listTwo, *listThree, *listFour;
    int i;
    int head;

    /*normal array*/
    printf("    test case one\n");
    list = createList();

    for(i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) 
    {
        list = addToFront(list, arr[i]);
        printList(list);
    }
    
    getLength(list);
    getFront(list);
    
    list = removeFromFront(list);
    printList(list);
    
    getLength(list);
    head = getFront(list);
    printf("The head of the list is: %d\n", head);
    printList(list);
    destroy(list);

    /*testing big numbers*/
    printf("\n    test case two\n");
    listTwo = createList();
    
    for(i = 0; i < sizeof(array)/sizeof(array[i]); i++) 
    {
        listTwo = addToFront(listTwo, array[i]);
        printList(listTwo);
    }
    
    getLength(listTwo);
    
    listTwo = removeFromFront(listTwo);
    printList(listTwo);
    
    getLength(listTwo);
    head = getFront(listTwo);
    printf("The head of the list is: %d\n", head);
    destroy(listTwo);

    /*empty array size of 1*/
    printf("\n    test case three\n");
    listThree = createList();

    for(i = 0; i < sizeof(arrayThree)/sizeof(arrayThree[i]); i++) 
    {
        listThree = addToFront(listThree, arrayThree[i]);
        printList(listThree);
    }
    
    getLength(listThree);
    
    listThree = removeFromFront(listThree);
    printList(listThree);
    
    getLength(listThree);
    head = getFront(listThree);
    printf("The head of the list is: %d\n", head);
    destroy(listThree);

    /*empty array size of 1*/
    printf("\n    test case four\n");
    listFour = createList();

    for(i = 0; i < sizeof(arrayFour)/sizeof(arrayFour[i]); i++) 
    {
        listFour = addToFront(listFour, arrayFour[i]);
        printList(listFour);
    }
    
    getLength(listFour);
    
    listFour = removeFromFront(listFour);
    printList(listFour);
    
    getLength(listFour);
    head = getFront(listFour);
    printf("The head of the list is: %d\n", head);
    destroy(listFour);


    /*Testing an empty list*/
    printf("\n    test case five\n");
    list = createList();

    list = removeFromFront(list);
    head = getFront(list);
    printf("The head of the list is(-1 if there is no head): %d\n", head);
    getLength(list);
    destroy(list);
    
    return 0;
}
