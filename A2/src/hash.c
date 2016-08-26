/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Hash ADT
 *LAST MODIFICATION: July 4th, 2014
 */
#include "hash.h"

/*preconditions: a size is passed in as a parameter
 *postconditions: A hashtable is created with its size that was passed in
*/
HT * create(int size)
{
    HT * newT;
    int i;
    newT = malloc(sizeof(HT));/*malloc for table*/
    newT->table = malloc(sizeof(Record *) * size);/*malloc for the table itself to hold the data*/

    if(newT == NULL || newT->table == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(1);
    }

    if(size < MINTABLESIZE)/*if the size is less than 1, then exit*/
    {
        printf("Size cannot be less than 1. Aborting.\n");
        exit(1);
    }

    for(i = 0; i < size; i++)/*create the table of the size specified*/
    {
        newT->table[i] = 0;
    }

    newT->size = size;/*store the size into the struct*/

    return newT;
}

/*preconditions: An initialized hash table and list is passed in as a parameter
 *postconditions: The hash table is filled with the contents of the linked list
*/
void fillTable(HT * hashTable, Record * theList)
{
    if(theList == NULL || hashTable == NULL)
    {
        printf("Cannot fill table, list is empty\n");
        return;
    }
    while(theList != NULL)/*while the list isnt null, insert the values from the list into the table*/
    {
        insert(hashTable, theList->firstName, theList->lastName, theList->phoneNumber);
        theList = theList->next;
    }
}

/*preconditions: An initialized list and the key is passed in as a parameter
 *postconditions: The key is hashed and then used to find if that hash number is stored.
*/
Record * lookup(HT * hashTable, char * keyEntered)
{
    Record * list;
    int found;
    unsigned int hashVal = hashFunc(hashTable, keyEntered);

    list = hashTable->table[hashVal];
    found = 0;

    if(list == NULL)/*if the list is null*/
    {
        return NULL;
    }

    while(list != NULL)/*while the list is not null, compare the entry and the stored number*/
    {
        if(strcmp(keyEntered,list->phoneNumber) == 0)/*if it is a match, return the table spot where the key is*/
        {
    
            return list;
            found = 1;
            break;
        }
        list = list->next;/*keep going to the next element*/
    }

    if(!found)/*if it is not found, return NULL*/
    {
        return NULL;      
    }

    return NULL;
}

int isDuplicate(HT * hashTable, char * key){
    
    int found;
    unsigned int hashVal = hashFunc(hashTable, keyEntered);
}

/*preconditions: An initialized hash table is passed in as a parameter and key is passed in 
 *postconditions: The value and key is deleted from the specified spot by searching the table
*/
void deleteValue(HT * hashTable, char * key)
{
    Record * ptr;
   /* Record * temp;*/
    /*unsigned int hashVal = hashFunc(hashTable, key);*/

    ptr = lookup(hashTable, key);
   /* temp = hashTable->table[hashVal];*/

    if(ptr == NULL)
    {
        return;
    }
    else
    {
        /*temp = ptr;*/
        destroyRecord(ptr);
        hashTable->size = hashTable->size - 1;
    }

}

/*preconditions: An initialized hash table is passed in as a parameter, key, new first name, new last name is passed in as well
 *postconditions: The name is changed to the new name and the key stays the same
*/
void update(HT * hashTable, char * key, char * newName, char * newLast)
{
    Record * list;

    list = lookup(hashTable, key);

    if(list == NULL)
    {
        printf("Entry could not be found. Did not update list.\n\n");
        return;
    }
    else
    {
        /*copy new value into the struct*/
        strcpy(list->firstName, newName);
        strcpy(list->lastName, newLast);
    }
}

/*preconditions: An initialized hashtable and key is passed in as a parameter
 *postconditions: Adds the last 3 numbers of the key together and key % table size to get the key for the hash table (Division)
*/
unsigned int hashFunc(HT * hashTable, char * key)
{
    unsigned int hashVal;
    unsigned int sum = 0;

    hashVal = 0;

    for(hashVal = HASHSTART; hashVal < PHONELENGTH; hashVal++)/*start at 7 and go till 10 to get the last 3 numbers in the phone number*/
    {
        sum += key[hashVal]; /*add the ASCII value together*/
    }

    return sum % hashTable->size; /*do the division hashing*/
}

/*preconditions: An initialized hash table is passed in as a parameter, first name, last name and phone number is passed in as well
 *postconditions: The record is inserted into its appropiate spot in the hash table by key
*/
void insert(HT * hashTable, char * name, char * last, char * num)
{
    Record * newList;
    int hashVal = hashFunc(hashTable, num);/*hash the key*/

    newList = malloc(sizeof(Record) + 1);

    if(newList == NULL)/*if it is null, end function*/
    {
        return;
    }

    /*Insert it into the list- separate chaining*/
    newList = createRecord(name,last,num);
    newList->next = hashTable->table[hashVal];
    hashTable->table[hashVal] = newList;
}

/*preconditions: An initialized hash table is passed in as a parameter
 *postconditions: The entries stored is printed from the hash table
*/
void printTable(HT * hashTable)
{
    int i;

    i = 0;

    /*This check was used for testing but it is commented out for the actual program because I needed the menu to loop*/
    /*If this was there it would cause a segfault because NULL was being passed*/
    if(hashTable == NULL)
    {
        printf("Sorry, you did not load a file. The program will now end.\n");
 c   }

    for(i = 0; i < hashTable->size; i++)
    {
        if(hashTable->table[i] != NULL)
        {
            printList(hashTable->table[i]);
        }       
    }
}

/*preconditions: Amount of nodes is passed in as the parameter
 *postconditions: The size of the table becomes 2/3 of the data size
*/
int calculateTableSize(int records)
{
    int size;

    size = ((records * 2) / 3);/*2/3 of the data size*/

    return size;
}

/*preconditions: An initialized hash table and key is passed in as a parameter
 *postconditions: Searches the hash table to see if the key entered exists as an element. If its null, it is not there else it is
 printed
*/
void reverseLookup(HT * hashTable, char * keyEntered)
{
    Record * search;

    search = lookup(hashTable, keyEntered);/*look to see if the key is in the table*/

    if(search == NULL)/*if not return null*/
    {
        printf("Sorry, the number you have entered is not in the directory.\n");
    }
    else/*else print the person*/
    {
        printf("\nPerson Found\n%s %s\n", search->firstName, search->lastName);
    }
}

/*preconditions: An initialized hash table is passed in as a parameter
 *postconditions: The memory used is freed
*/
void destroyTable(HT * hashTable)
{
    int i;

    if(hashTable == NULL)
    {
        return;
    }

    for(i = 0; i < hashTable->size; i++)
    {
        if(hashTable != NULL)
        {
            destroyList(hashTable->table[i]);
        }
        else
        {
            return;
        }
    }

    free(hashTable->table);
    free(hashTable);
}
