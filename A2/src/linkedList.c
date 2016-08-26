/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Creating functions for the linked list
 *LAST MODIFICATION: July 4th, 2014
 */
#include "linkedList.h"

/*Creates an empty list*/
/*preconditions: none
 *postconditions: An empty list is created
*/
Record * createList()
{
    Record * theList;

    theList = NULL; /*set head to null*/

    return theList;
}

/*preconditions: 3 initialized chars are passed in as parameters
 *postconditions: The new node stored in the struct is returned
*/
Record * createRecord(char * first, char * last, char * phone)
{
    Record * newRec = malloc(sizeof(Record));

    /*malloc and store into struct*/
    newRec->firstName = malloc(sizeof(char) * (strlen(first) + 1));
    newRec->lastName = malloc(sizeof(char) * (strlen(last) + 1));
    newRec->phoneNumber = malloc(sizeof(char) * (strlen(phone) + 1));
    strcpy(newRec->firstName, first);
    strcpy(newRec->lastName, last);
    strcpy(newRec->phoneNumber, phone);
    /*newRec->phoneNumber = phone;*/
    newRec->next = NULL;

    if(newRec == NULL)
    {
        printf("Out of memory\n");
        return NULL;
    }

    return(newRec);
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The memory used is freed for a single record
*/
void destroyRecord(Record * theRecord)
{
    /*free all elements in struct*/
    free(theRecord->firstName);
    free(theRecord->lastName);
    free(theRecord->phoneNumber);
}

/*preconditions: A line from the file is passed in as a parameter
 *postconditions: The line is parsed and stored into the struct
*/
Record * storeDirectory(char * line)
{
    Record * head;
    char * firstN;
    char * lastN;
    char * phoneNum;

    /*strtok and store each word into its own pointer*/
    firstN = strtok(line, ",");
    lastN = strtok(NULL, ","); 
    phoneNum = strtok(NULL, ",");

    head = createRecord(firstN, lastN, phoneNum);/*store them into the struct*/

    return head;   
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The linked list is sorted by phone numbers
*/
void sort(Record * theList)
{
    Record * node;
    Record * temp;

    /*node = theList;
    temp = NULL;*/

    while(node->next != NULL)
    {
        if(strcmp(node->phoneNumber, node->next->phoneNumber) > 0)
        {
            temp = node;
            node = node->next;
            temp->next= node;
            node = temp;
        }

        node = node->next;
    }
}
/*preconditions: an initialized list is passed in and the data that will be added to that list
 *postconditions: A new head of the list is outputted with the remaining nodes
*/
Record * addToFront(Record * theList, Record * toBeAdded)/*Add notes to the front of current head*/
{
    Record * newNode;

    newNode = NULL;
   /* toBeAdded = createRecord(firstAdd, lastAdd, numAdd);*/
    
    if(isEmpty(theList) == 1)
    {
       /* return NULL;*/
        theList = newNode;
        theList->next = NULL;
    }
    else/*continuing adding to the front*/
    {
        toBeAdded->next = theList;
        theList = toBeAdded;
    }

    return theList;
}
/*preconditions: an initialized list gets passed in as the parameter
 *postconditions: Removes the current head of the list and makes a new head the next element
*/
Record * removeFromFront(Record * theList)/*function to remove the head*/
{
    Record * temp;
    
    temp = theList;

    if(isEmpty(theList) == 1)/*if the list is empty do not remove anything*/
    {
        printf("The list is empty, no head to remove.\n");
    }
    else /*remove the head and make a new head*/
    {
        temp = theList->next;
    }

    return temp;
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The entire list is printed
*/
void printList(Record *  theList)/*prints entire list recursively*/
{
    if(isEmpty(theList) == 1)/*won't print anything if the list is empty*/
    {
        /*printf("List is empty, nothing to print.\n");*/
        return;
    }

    else
    {
        printf ("%s %s %s", theList->firstName, theList->lastName, theList->phoneNumber);
        printf("\n");
        printList(theList->next);
    }
}

/*preconditions: An initialized List is passed in as a parameter
 *postconditions: If the list is empty, returns true else returns false
*/
int isEmpty(Record * theList)/*checks if the list is empty*/
{
    if(theList == NULL)/*if it is empty return true(1)*/
    {
        return 1;
    }
    
    return 0;/*else return false (0)*/
}

/*preconditions: An initialized List is passed in as a parameter
 *postconditions: Counts the amount of nodes in the list and returns that value
*/
int count(Record * theList)
{
    int x;

    x = 0;

    while(theList != NULL)/*while the list is not null, keep counting the records*/
    {
        theList = theList->next;
        x++;
    }

    return x;
}

/*preconditions: An initialized list is passed in as a parameter
 *postconditions: The memory used is freed
*/
void destroyList(Record * theList)/*to free memory*/
{
    Record * temp;

    if(isEmpty(theList) == 1)/*if list is empty there is nothing to free*/
    {
        /*printf("List is empty, nothing to destroy.\n");*/
        return;
    }

    while(theList != NULL)/*free the memory*/
    {
        temp = theList;
        theList = temp->next;
        free(theList);
    } 
}



