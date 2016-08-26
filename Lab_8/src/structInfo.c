#include "structInfo.h"
#include "treeInterface.h"

/*preconditions: a name, food and rating is passed in as the parameters
 *postconditions: new node is stored into the struct
*/
Restaurant * createNode(char * name, char * food, int rate)
{
    /*Initialization of vairables*/
    Restaurant * newInfo;

    /*if memory cannot be malloced, exit the program*/
    if((newInfo = malloc(sizeof(Restaurant))) == NULL)
    {
     	printf("Out of memory. Aborting.\n");
        exit(0);
    }

    /*create a new node to store into the struct*/
    newInfo->rName = malloc(sizeof(char) * strlen(name) + 1);
    newInfo->foodType = malloc(sizeof(char) * strlen(food) + 1);
    strcpy(newInfo->rName, name);
    strcpy(newInfo->foodType, food);
    newInfo->rating = rate;

    /*if the node could not be created, exit the program*/
    if(newInfo == NULL)
    {
     	printf("Out of memory. Aborting.\n");
        exit(1);
    }

    return newInfo;
}

/*preconditions: 2 data entries are entered as the parameters
 *postconditions: the 2 data are compared to see where they are placed within the ADT by name
*/
int compareName(void * data1, void * data2)
{
    /*Cast the void * parameters to the Restaurant ADT*/
    Restaurant * a = (Restaurant *)data1;
    Restaurant * b = (Restaurant *)data2;

    /*If the first restaurant name is bigger than the second one then return a positive number*/
    if(strcmp(a->rName, b->rName) > 0)
    {
     	return 1;
    }
    /*if the first name is smaller than the second one, then return a negative number*/
    if(strcmp(a->rName, b->rName) < 0)
    {
     	return -1;
    }
    /*if the names are the same, return 0*/
    if(strcmp(a->rName, b->rName) == 0)
    {
     	if(a->rating > b->rating)
        {
            return 1;
        }
	if(a->rating < b->rating)
        {
            return -1;
        }
    }

    return 0;
}

/*preconditions: 2 data entries are entered as the parameters
 *postconditions: the 2 data are compared to see where they are placed within the ADT by rating
*/
int compareRating(void * data1, void * data2)
{
    /*Cast the void * parameter to the Restaurant ADT*/
    Restaurant * a = (Restaurant *)data1;
    Restaurant * b = (Restaurant *)data2;

    /*if the first rating is bigger than another, return positive*/
    if(a->rating > b->rating)
    {
     	return 1;
    }
    /*if the first rating is smaller than another, return negative*/
    if(a->rating < b->rating)
    if(a->rating < b->rating)
    {
     	return -1;
    }
    /*if the ratings are the same, return 0*/
    if(a->rating == b->rating)
    {
     	if(strcmp(a->rName, b->rName) > 0)
        {
            return 1;
        }
	if(strcmp(a->rName, b->rName) < 0)
        {
            return -1;
        }
    }

    return 0;
}

/*preconditions: a parameter is passed in and cast to the Restaurant ADT
 *postconditions: the parameter is printed
*/
void printNode(void * parameter)
{
    /*cast void parameter to Restaurant ADT*/
    Restaurant * a = (Restaurant *)parameter;

    if(a == NULL)
    {
     	printf("printNode() NULL parameter\n");
        return;
    }

    /*print out the data in the struct*/
    printf("%s[%d]:%s\n", a->rName, a->rating, a->foodType);
}

/*preconditions: the data is entered that needs to be destoryed
 *postconditions: data is freed and destroyed
*/
void destroyDataNode(void * node)
{
    /*destroyTree(node);*/
    free(node);
}

/*preconditions: A line from the file is passed in as a parameter
 *postconditions: The line is parsed and stored into the struct
*/
Restaurant * storeDirectory(char * line)
{
    Restaurant * root;
    char * resName;
    char * resType;
    char * resRate;
    int rRating;

    rRating = 0;

    /*strtok and store each word into its own pointer*/
    resName = strtok(line, ",");
    resType = strtok(NULL, ",");
    resRate = strtok(NULL, ",");
    rRating = atoi(resRate);

    root = createNode(resName, resType, rRating);/*store them into the struct*/

    return root;
}

/*preconditions: An initialized tree is passed in as a parameter
 *postconditions: Tree is printed in a graph form
*/
void printOrder(Tree * theTree)
{
    Tree * root;
    /*Tree * left, * right;*/
    
    if(theTree == NULL)
    {
        return;
    }
    else
    {
    
        root = getRootData(theTree);
        printNode(root);

        /*left = getLeftSubtree(root);
        right = getRightSubtree(root);

        printOrder(left);
        printOrder(right);*/
        /*right = getRightSubtree(theTree);
        printOrder(right);*/
    }
}

