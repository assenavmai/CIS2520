/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Header file for hash.c
 *LAST MODIFICATION: July 4th, 2014
 */
#include "linkedList.h"

#define PHONELENGTH 10
#define HASHSTART 7
#define MINTABLESIZE 1
struct Hash{
    int size;
    Record ** table;
};

typedef struct Hash HT;

/*Creates the hash table to the appropiate size
 *@param size: the size
 *Returns the new hash table
 */
HT * create(int size);

/*Fills the hash table with data from the linked list
 *@param hashTable: initialized hash table
 *@param theList: linked list of data
 *Returns the new head of the list
 */
void fillTable(HT * hashTable, Record * theList);

/*Fills the hash table with data from the linked list
 *@param hashTable: initialized hash table
 *@param keyEntered: key to hash
 *Returns NULL if not found, returns the list if it is found in hash table
 */
Record * lookup(HT * hashTable, char * keyEntered);

/*Deletes a value from the specified spot in the table
 *@param hashTable: initialized hash table
 *@param key: key to hash
 *no return value
 */
void deleteValue(HT * hashTable, char * key);

/*Updates a specified spot in the table, the key remains the same
 *@param hashTable: initialized hash table
 *@param newName: first name 
 *@param newLat: last name
 *@param key: phone number
 *No return value
 */
void update(HT * hashTable, char * key, char * newName, char * newLast);

/*Gets the hashed values for the hash table
 *@param hashTable: initialized hash table
 *@param keyEntered: key to hash
 *Returns the hashed key
 */
unsigned int hashFunc(HT * hashTable, char * key);

/*Fills the hash table with data from the linked list
 *@param hashTable: initialized hash table
 *@param name: first name 
 *@param last: last name
 *@param keyEntered: phone number
 *No return value
 */
void insert(HT * hashtable, char * name, char * last, char * num);

/*Creates the hash table to the appropiate size
 *@param hashTable: initialized hash table
 *No return value
 */
void printTable(HT * hashTable);

/*Creates the hash table to the appropiate size
 *@param records: amount of nodes in linked list
 *Returns the calculated hash table size
 */
int calculateTableSize(int records);

/*Finds the name of a person from key entered
 *@param hashTable: initialized hash table
 *@param keyEntered: key to hash
 *No return value
 */
void reverseLookup(HT * hashTable, char * keyEntered);

/*Deletes memory from hashTable and linked list
 *@param hashTable: initialized hash table
 *No return value
 */
void destroyTable(HT * hashTable);