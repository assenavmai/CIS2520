#include "hash.h"

int main(int argc, char const *argv[])
{

    HT * myTable;
    FILE * f;
    int fun;
    char line[400];
    fun = 0;

    f = fopen("file.txt", "r");
    myTable = create(250);


    while(fgets(line, sizeof(line), f) != NULL)
    {
        fun = insert(myTable, line);
    }

    printStats( myTable);


    return 0;
}