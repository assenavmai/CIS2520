/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: To test the Fraction ADT
 *LAST MODIFICATION: May 15, 2014
 */
#include "fraction.h"

int main(void)
{
    Fraction * fracOne, * fracTwo, * answer;
    int i;

        fracOne = NULL;
    fracTwo = NULL;

    /*FIRST TEST CASE*/
    /*Makes sure if the denominator and numerator is equal that the output is 1*/
    /*Makes sure that when the numerator is 0 the output is 0*/
    printf(" first test case...IF DENOMINATOR EQUALS NUMERATOR = 1\n");
    fracOne = createFraction(4,4);
    fracTwo = createFraction(0,1); 

    printf("1st Fraction: ");
    printFraction(fracOne);
    printf("2nd Fraction: ");
    printFraction(fracTwo);

    answer = add(fracOne, fracTwo);
    printf("Added Answer: ");
    printFraction(answer);

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);

    /*SECOND TEST CASE*/
    /*Makes sure when the fractions are the same they output the correct answer*/
    /*Tests if statement in add(), if the denominators are the same...just add the numerators*/
    printf("\n second test case...ADDING NUMERATORS WITH SAME DENOMINATORS\n");
    fracOne = createFraction(1,4);
    fracTwo = createFraction(1,4); 

    printf("1st Fraction: ");
    printFraction(fracOne);
    printf("2nd Fraction: ");
    printFraction(fracTwo);

    answer = add(fracOne, fracTwo);
    printf("Added Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Added Answer Simplified: ");
    printFraction(answer);

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);

    /*Third TEST CASE*/
    /*Just testing a normal fraction to see if the output is correct*/
    printf("\n Third test case...NORMAL FRACTION, NO REDUCING\n");
    fracOne = createFraction(3,5);
    fracTwo = createFraction(4,7); 

    printf("1st Fraction: ");
    printFraction(fracOne);
    printf("2nd Fraction: ");
    printFraction(fracTwo);

    answer = add(fracOne, fracTwo);
    printf("Added Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Added Answer Simplified: ");
    printFraction(answer);

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);

    /*Fourth TEST CASE*/
    /*Testing improper fractions that can be reduced*/
    /*At this point, no mixed fractions*/
    printf("\n Fourth test case...REDUCING IMPROPER FRACTIONS\n");
    fracOne = createFraction(16,8);
    fracTwo = createFraction(12,4); 

    printf("1st Fraction: ");
    printFraction(fracOne);
    printf("2nd Fraction: ");
    printFraction(fracTwo);

    answer = add(fracOne, fracTwo);
    printf("Added Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Added Answer Simplified: ");
    printFraction(answer);

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);

    /*fifth TEST CASE*/
    /*Testing negative fractions*/
    /*Checks to see when negative denominator, it moves it to the numerator*/
    printf("\n fifth test case...NEGATIVE DENOMINATOR GOES TO NUMERATOR\n");
    fracOne = createFraction(3,-5);
    fracTwo = createFraction(4,7); 

    printf("1st Fraction: ");
    printFraction(fracOne);
    printf("2nd Fraction: ");
    printFraction(fracTwo);

    answer = add(fracOne, fracTwo);
    printf("Added Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Added Answer Simplified: ");
    printFraction(answer);

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);

    /*sixth TEST CASE*/
    /*Testing negative fractions*/
    /*Checks to see that negatives cancel eachother out when multiplied*/
    printf("\n sixth test case...NEGATIVES CANCEL EACHOTHER\n");
    fracOne = createFraction(-3,5);
    fracTwo = createFraction(-4,7); 

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);

    /*seventh TEST CASE*/
    /*Testing NULL fractions*/
    /*Checks to see that negatives cancel eachother out when multiplied*/
    /*Will EXIT on fail*/
    /*Commented out so it will not exit*/
    
    /*printf("\n seventh test case... NULL VALUES\n");
    fracOne = createFraction(-3,5);
    fracTwo = NULL;

    answer = multiply(fracOne, fracTwo);
    printf("Multiplied Answer: ");
    printFraction(answer);
    
    simplify(answer);
    printf("Multiplied Answer Simplified: ");
    printFraction(answer);*/

    /*EIGTH TEST CASE*/
    /*When the denominator is 0, it should print out Error to the user*/
    /*Does not exit for the purpose of continuing test cases*/
    /*Commented out because will exit on failure*/
    /*printf("\n eigth test case...DENOMINATOR IS 0\n");
    fracOne = createFraction(1,4);
    fracTwo = createFraction(2,0); */

    for(i = 0; i < 6; i++)/*Destroy fraction for everytime used in test cases*/
    {
        destroyFraction(fracOne);
        destroyFraction(fracTwo);
        destroyFraction(answer);
    }    


    return 0;
}