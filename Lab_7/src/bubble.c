/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *LAST MODIFICATION: July 4th, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void swap(int * x, int * y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

/*preconditions: an array is passed in as the parameter also how much times the loop should go for
  post conditions: array is sorted in ascending order*/
void bubbleSort(int a[], int n)
{
    int i, j;/*intialize variables*/

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);/*larger one goes down*/
            }
        }
    }
}
/*preconditions: an array is passed in as the parameter also how much times the loop should go for
  post conditions: array is sorted in ascending order recursively*/
void rBubbleSort(int a[], int n)
{
    int i;/*initializing variables*/

    for(i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i + 1])
        {
            swap(&a[i], &a[i + 1]);/*larger one goes down*/
        }
    }

        if(n > 2)/*swap remaining element*/
        {
            rBubbleSort(a, n - 1);
        }
}