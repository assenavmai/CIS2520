/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Header file for linkedList.h
 *LAST MODIFICATION: July 4th, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

struct Directory{ /*linked list*/
  char * firstName;
  char * lastName;
  char *  phoneNumber;
  struct Directory * next;
};

typedef struct Directory Record;

/*Description:
 *Creates an empty list
 *Parameters:
 *none
 *Return:
 *Returns the dummy node which is the head of the list
 */
Record * createList();

/*Creates a new node with information; stores info into struct
 *@param first: first name
 *@param last: last name
 *@param: phone number
 *Returns new list with the node in it
 */
Record * createRecord(char * first, char * last, char * phone);

/*Destory a single record
 *@param theRecord: the list of information
 *no return value
 */
void destroyRecord(Record * theRecord);

/*Takes a line from the file and parses it then stores it into the struct
 *@param line: the line of information from the file
 *returns the new node in the list 
 */
Record * storeDirectory(char * line);

/*Sorts a linked list
 *@param theList: the list of information
 *no return value
 */
void sort(Record * theList);


/*Description:
 *Adds a node to the front of the list using initNode()
 *Parameters:
 *theList: the linked list
 *toBeAdded: the data going to be entered into the list
 *Return:
 *Returns the new head of the list
 */
Record * addToFront(Record * theList, Record * toBeAdded);

/*Description:
 *Removes the first node in the list
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
Record * removeFromFront(Record * theList);


/*Description:
 *Prints the entire linkedlist
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
void printList(Record *  theList);

/*Description:
 *Checks if the list is empty
 *Parameters:
 *theList: the linked list
 *Return:
 *returns 1 if it is empty and 0 if not
 */
int isEmpty(Record * theList);

/*Counts the amount of nodes in a linked list
 *@param theList: the list of information
 *Returns the amount of nodes in the list
 */
int count(Record * theList);

/*Description:
 *Destroys linked list: free memory
 *Parameters:
 *theList: the linked list
 *Return:
 *No return value
 */
void destroyList(Record * theList);

