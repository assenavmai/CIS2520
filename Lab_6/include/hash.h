#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct List
{
    char * str;
    struct List * next;
};
typedef struct List Node;


struct Hash
{
    int size;
    Node ** table;
};
typedef struct Hash HT;

HT * create(int size);
unsigned int hashFunc(HT * hashtable, char * str);
Node * lookup(HT * hashtable, char * str);
int insert(HT * hashtable, char * str);
int insert(HT * hashtable, char * str);
void destroy(HT * hashtable);
void printStats(HT * hasht);

char * strdup(const char * str);
