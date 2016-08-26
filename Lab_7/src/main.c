#include "bubble.h"

/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *LAST MODIFICATION: July 4th, 2014
 */
int main(int argc, char const *argv[])
{
    /*Initializing Variables*/
    int iterOne[TESTONE];
    int rOne[TESTONE];
    int iterTwo[TESTTWO];
    int rTwo[TESTTWO];
    int iterThree[TESTTHREE];
    int rThree[TESTTHREE];
    int iterFour[TESTFOUR];
    int rFour[TESTFOUR];
    int iterFive[TESTFIVE];
    int rFive[TESTFIVE];
    int iterSix[TESTSIX];
    int rSix[TESTSIX];
    int r1;
    int i;
    int tI, tR;
    time_t iStart, iEnd, rStart, rEnd;

    /*Start Random */
    srand(time(NULL));

    /*tetsing size 5000*/
    printf("   testing array size of 5000\n");

    for(i = 0; i < TESTONE; i++)
    {
        r1=1 +rand() % RANDOM; /*RANDOM is 3000*/ /*used for every test*/
        /*fill up the arrays*/
        iterOne[i] = r1;
        rOne[i] = r1;
    }
    /*Start the clock for the iterative function and time how long it takes*/
    iStart = clock();
    bubbleSort(iterOne, TESTONE);
    iEnd = clock();

    /*Start the clock for the for the recurisve function*/
    rStart = clock();
    rBubbleSort(rOne, TESTONE);
    rEnd = clock();

    /*calculate the algorithms time*/
    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    /*print it*/
    printf("Iterative time taken in seconds: %d\n", tI);
    printf("Recursive time taken in seconds: %d\n", tR);

    
    /*testing size 15000*/
    printf("\n   testing array size of 15000\n");
    for(i = 0; i < TESTTWO; i++)
    {
        r1=1 +rand() % RANDOM;/*get random numbers and fill array with them*/
        iterTwo[i] = r1;
        rTwo[i] = r1;
    }
    /*sort iteratively*/
    iStart = clock();
    bubbleSort(iterTwo, TESTTWO);
    iEnd = clock();

    /*sort recursively*/
    rStart = clock();
    rBubbleSort(rTwo, TESTONE);
    rEnd = clock();

    /*calculate time taken*/
    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    printf("Iterative time taken in seconds: %d\n", tI);
    printf("Recursive time taken in seconds: %d\n", tR);

    
    /* Test of size 25000*/
    printf("\n   testing array size of 25000\n");
    for(i = 0; i < TESTTHREE; i++)
    {
        r1=1 +rand() % RANDOM;/*fill array with random numbers*/
        iterThree[i] = r1;
        rThree[i] = r1;
    }
    /*sort iteratively*/
    iStart = clock();
    bubbleSort(iterThree, TESTTHREE);
    iEnd = clock();

    /*sort recursively*/
    rStart = clock();
    rBubbleSort(rThree, TESTONE);
    rEnd = clock();

    /*calcualte time taken for each algorithm*/
    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    printf("Iterative time taken in seconds: %d\n", tI);/*print result*/
    printf("Recursive time taken in seconds: %d\n", tR);

    
    /* Test size 50 000*/
    printf("\n   testing array size of 50000\n");
    for(i = 0; i < TESTFOUR; i++)
    {
        r1=1 +rand() % RANDOM;/*fill array with random numbers*/
        iterFour[i] = r1;
        rFour[i] = r1;
    }
    /*sort iteratively*/
    iStart = clock();
    bubbleSort(iterFour, TESTFOUR);
    iEnd = clock();

    /*sort recursively*/
    rStart = clock();
    rBubbleSort(rFour, TESTONE);
    rEnd = clock();

    /*calculate time taken for each algorithm*/
    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    printf("Iterative time taken in seconds: %d\n", tI);/*print results*/
    printf("Recursive time taken in seconds: %d\n", tR);

    
    /* Test size 75000*/
    printf("\n   testing array size of 75000\n");
    for(i = 0; i < TESTFIVE; i++)
    {
        r1=1 +rand() % RANDOM;/*fill array with random numbers*/
        iterFive[i] = r1;
        rFive[i] = r1;
    }
    /*sort iteratively*/
    iStart = clock();
    bubbleSort(iterFive, TESTFIVE);
    iEnd = clock();

    /*sort recursively*/
    rStart = clock();
    rBubbleSort(rFive, TESTONE);
    rEnd = clock();

    /*calculate time taken*/
    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    printf("Iterative time taken in seconds: %d\n", tI);/*print results*/
    printf("Recursive time taken in seconds: %d\n", tR);

    /*Iterative Test*/
    /*Commented out because it takes much time, results in testing.txt*/
   /* printf("\n   testing array size of 100000\n");
    for(i = 0; i < TESTSIX; i++)
    {
        r1=1 +rand() % RANDOM;
        iterSix[i] = r1;
        rSix[i] = r1;
    }
    iStart = clock();
    bubbleSort(iterSix, TESTSIX);
    iEnd = clock();

    rStart = clock();
    rBubbleSort(rSix, TESTSIX);
    rEnd = clock();

    tI = (iEnd - iStart) / CLOCKS_PER_SEC;
    tR = (rEnd = rStart) / CLOCKS_PER_SEC;
    printf("Iterative time taken in seconds: %d\n", tI);
    printf("Recursive time taken in seconds: %d\n", tR);*/


    return 0;
}
