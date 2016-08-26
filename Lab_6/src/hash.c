#include "hash.h"

HT * create(int size)
{
    HT * newT;
    int i;

    newT = malloc(sizeof(HT));
    newT->table = malloc(sizeof(Node *) * size);

    if(newT == NULL || newT->table == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(1);
    }

    if(size < 1)
    {
        printf("Size cannot be less than 1. Aborting.\n");
        exit(1);
    }

    for(i = 0; i < size; i++)
    {
        newT->table[i] = 0;
    }

    newT->size = size;

    return newT;
}

unsigned int hashFunc(HT * hashtable, char * key)
{
    unsigned int hashval;
    int sum = 0;

    hashval = 0;

    for(hashval = 0; hashval < strlen(key); hashval++)
    {
        sum += key[hashval];
    }

    return sum % hashtable->size;
}

Node * lookup(HT * hashtable, char * str)
{
    Node * list;
    unsigned int hashval = hashFunc(hashtable, str);

    /* Go to the correct list based on the hash value and see if str is
     * in the list.  If it is, return return a pointer to the list element.
     * If it isn't, the item isn't in the table, so return NULL.
     */
    for(list = hashtable->table[hashval]; list != NULL; list = list->next) 
    {
        if (strcmp(str, list->str) == 0) 
        {
            return list;
        }
    }
    return NULL;
}

int insert(HT * hashtable, char * str)
{
    Node * newList;
    Node * currentList;
    unsigned int hashval = hashFunc(hashtable, str);

    newList = malloc(sizeof(Node));

    if(newList == NULL)
    {
        return 1;
    }

    /* Does item already exist? */
    currentList = lookup(hashtable, str);
        /* item already exists, don't insert it again. */
    if (currentList != NULL) 
    {
        return 2;
    }

    /* Insert into list */
    newList->str = strdup(str);
    newList->next = hashtable->table[hashval];
    hashtable->table[hashval] = newList;

    return 0;
}


void destroy(HT * hashtable)
{
    int i;
    Node *list, *temp;

    if (hashtable == NULL) 
    {
        return;
    }

    /* Free the memory for every item in the table, including the 
     * strings themselves.
     */
    for(i=0; i < hashtable->size; i++) 
    {
        list = hashtable->table[i];
        
        while(list != NULL) 
        {
            temp = list;
            list = list->next;
            free(temp->str);
            free(temp);
        }
    }

    /* Free the table itself */
    free(hashtable->table);
    free(hashtable);
}

char * strdup(const char * str)
{
    int n;
    char * dup;

    n = strlen(str) + 1;
    dup = malloc(n * sizeof(char));

    if(dup)
    {
        strcpy(dup, str);
    }

    return dup;
}

void printStats(HT * hasht)
{
    int j, i;
    int fr, used, coll;
    int chainMax;
    int chainSum;
    Node * temp;

    i = 0;
    chainSum = 0;
    chainMax = 0;

    fr = used = coll = 0;

    for(; i < hasht->size; i++)
    {
        j = 0;

        if(hasht->table[i] == NULL)
        {
            fr++;
        }
        else if(hasht->table[i]->next == NULL)
        {
            chainSum++;
            used++;
        }
        else
        {
            temp = hasht->table[i];

            for(; temp != NULL; temp = temp->next)
            {
                j++;
                chainSum++;

                if(j > chainMax)
                {
                    chainMax = j;
                }
            }
            coll++;
        }
    }

    printf("----------STATS-----------\n");
    printf("Table size: %d\n# of Items: %d\n", hasht->size, chainSum);
    printf("Cells used: %d\nCells free: %d\n", used + coll, fr);
    printf("Collisions: %d\npercentage used: %5.3f\n", coll, ((double)(used + coll) / hasht->size) * 100);
    printf("%% of them collided: %5.3f\nLongest chain: %d\n", ((double)(coll) / (double)(used + coll) * 100), chainMax);
    printf("Avg chain length: %5.2f\n", (double)chainSum / (hasht->size - fr));
    printf("Avg collided length: %5.2f\n", (double)(chainSum - used) / (coll));
}
