/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Testing file for Hash ADT
 *LAST MODIFICATION: July 4th, 2014
 */
#include "hash.h"

#define TABLESIZE 10

int main(int argc, char const *argv[])
{
    /*Initializing variables*/
    HT * myTable;
    HT * nullTable;
    Record * head = NULL;
    Record * recordPtr;
    FILE * f;
    char line[200];
    char find[] = "9056482510";
    char phoneFind[] = "6194657212";
    int amount;
    int size;

    amount = 0;
    size = 0;

    f = fopen("directory.txt", "r");/*open file*/

    if(f == NULL)/*if file null, exit*/
    {
        fprintf(stderr, "Error. The file could not be opened.\n");
        exit(1);
    }

    /*testing functions reaction to null*/
    printf("    TESTING NULL VALUES\n");
    nullTable = create(5);
    fillTable(nullTable,head);
    printTable(nullTable);
    reverseLookup(nullTable, find);
    update(nullTable, find, "Vanessa", "White");
    destroyTable(nullTable);

    printf("\n\n   TESTING ALL FUNCTIONS NORMALLY\n");
    fgets(line, sizeof(line), f);/*get the head of the list(first line in text file)*/
    line[strlen(line) - 1] = '\0';
    head = storeDirectory(line);/*parse input*/

    while(fgets(line, sizeof(line), f) != NULL)/*read the rest of the file*/
    {
        line[strlen(line) - 1] = '\0';/*remove newline on each line*/
        recordPtr = storeDirectory(line);/*parse input*/
        head = addToFront(head, recordPtr);
        amount = count(recordPtr);
    }
    /*calculating size and storing file into table*/
    printf("Size before caluculation: %d\n", amount);
    size = calculateTableSize(amount);
    printf("Size after calculation (2/3 data size): %d", size);
    myTable = create(size);
    fillTable(myTable, head);
    printf("\nTHE TABLE\n");
    printTable(myTable);

    printf("\nNumber to lookup: %s\n", find);/*lookup non exisiting number*/
    reverseLookup(myTable, find);

    /*lookup exisiting number*/
    printf("\nNumber to lookup: %s\n", phoneFind);
    reverseLookup(myTable, phoneFind);
    printf("\n");

    /*deleteValue(myTable, "0214568523");
    printTable(myTable);
    printf("%d\n", myTable->size);*/
    printf("\n Updating update()\n");/*testing update()*/
    update(myTable, "9058465655", "Vanessa", "White");
    printf("\nUPDATED\n");
    printTable(myTable);

    destroyTable(myTable);/*destroying*/

    /* test for null*/
    printTable(myTable);
    printf("\nTable did not print, destroy successful\n");

    return 0;
}