/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Test the functions in lab2.c
 *LAST MODIFICATION: May 23, 2014
 */
#include "lab2.h"

int main(void)
{
    int arr[3] = {1,2,3}; /*array of test data*/
    int array[7] = {100,200,300,1000,2000,10000,10000000};
    int arrayThree[1];
    int arrayFour[5] = {-2568,-898,1245,-54964,-556};
    Node * list, *listTwo, *listThree, *listFour;
    int i;

    /*normal array*/
    printf("    test case one\n");
    list = createList();

    list = removeFromFront(list);
    getFront(list);
    getLength(list);
    destroy(list);

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
    getFront(list);
    printList(list);
    destroy(list);

    /*testing big numbers*/
    printf("\n    test case two\n");
    listTwo = createList();
    
    listTwo = removeFromFront(listTwo);
    getFront(listTwo);
    getLength(listTwo);
    destroy(listTwo);

    for(i = 0; i < sizeof(array)/sizeof(array[i]); i++) 
    {
        listTwo = addToFront(listTwo, array[i]);
        printList(listTwo);
    }
    
    getLength(listTwo);
    
    listTwo = removeFromFront(listTwo);
    printList(listTwo);
    
    getLength(listTwo);
    getFront(listTwo);
    destroy(listTwo);

    /*empty array size of 1*/
    printf("\n    test case three\n");
    listThree = createList();
    
    listThree = removeFromFront(listThree);
    getFront(listThree);
    getLength(listThree);
    destroy(listThree);

    for(i = 0; i < sizeof(arrayThree)/sizeof(arrayThree[i]); i++) 
    {
        listThree = addToFront(listThree, arrayThree[i]);
        printList(listThree);
    }
    
    getLength(listThree);
    
    listThree = removeFromFront(listThree);
    printList(listThree);
    
    getLength(listThree);
    getFront(listThree);
    destroy(listThree);

    /*empty array size of 1*/
    printf("\n    test case four\n");
    listFour = createList();
    
    listFour = removeFromFront(listFour);
    getFront(listFour);
    getLength(listFour);
    destroy(listFour);

    for(i = 0; i < sizeof(arrayFour)/sizeof(arrayFour[i]); i++) 
    {
        listFour = addToFront(listFour, arrayFour[i]);
        printList(listFour);
    }
    
    getLength(listFour);
    
    listFour = removeFromFront(listFour);
    printList(listFour);
    
    getLength(listFour);
    getFront(listFour);
    destroy(listFour);
    
    return 0;
}
