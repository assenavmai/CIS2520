/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: The functions used for the ADT
 *LAST MODIFICATION: May 15, 2014
 */
#include "fraction.h"

/*
 * preconditions: none
 * postconditions: a fraction is created with the appropiate numerator and denominator
 *     if there was no memory malloced properly, it will return NULL
 *     if the denominator entered is 0 the program will exit
 */
Fraction * createFraction (int numer, int denom)
{
    /*Allocating memory to store values*/
    Fraction * info = malloc(sizeof(Fraction));
    
    /*pointing the information to store into struct*/
    info->numerator = numer;
    info->denominator = denom;

    if(info == NULL)/*If it is NULL, memory was not allocated properly*/
    {
        printf("Out of memory\n");
        return NULL;
    }

    if(info->denominator == 0)/*If the denominator is 0, exit the program*/
    {
        printf("Error: Denominator cannot be zero\n");
        printf("Exiting...\n");
        exit(1);
    }

    return (info);
}

/*
 * preconditions: an initialized Fraction is given as the parameter
 * postconditions: if the fraction that is passed in is NULL, the program will exit
 */
int getNumerator(Fraction * theFraction)
{

    if(theFraction == NULL)/*If the fraction they are trying to pass through is null, exit the program*/
    {
        printf("There is no numerator.\n");
        printf("Exiting...\n");
        exit(1);
    }

    return theFraction->numerator;
}
/*
 * preconditions: an initialized Fraction is given as the parameter
 * postconditions: if the fraction that is passed in is NULL or has a denominator of 0 the program will exit
*/    
int getDenominator(Fraction * theFraction)
{
    if(theFraction == NULL)/*if the fraction they are trying to pass through is NULL, exit the program*/
    {
        printf("There is no denominator.\n");
        printf("Exiting...\n");
        exit(1);
    }

    if(theFraction->denominator == 0)/*Once again, check if the denominator is 0, exit if true*/
    {
        printf("Error: The denominator cannot be 0.\n");
        printf("Exiting...\n");
        exit(1);
    }

    return theFraction->denominator;
}

/*
 * preconditions: two initialized fractions are passed in as parameters
 * postconditions: the two fractions are added together and the result is placed in a new Fraction variable that is returned to the calling procedure
*/
Fraction * add(Fraction * fracOne, Fraction * fracTwo)
{
    Fraction * result = malloc(sizeof(Fraction));/*Allocate memory to store final answer*/

    /*Initialization of variables*/
    int numerOne, denomOne;
    int numerTwo, denomTwo;
    int finalNumer;
    int largestCommonDenom;

    /*Get the numerator and denominator of fraction 1 & 2*/
    numerOne = getNumerator(fracOne);
    denomOne = getDenominator(fracOne);

    numerTwo = getNumerator(fracTwo);
    denomTwo = getDenominator(fracTwo);

    if(denomOne == denomTwo) /*if the denominators are equal, just add the numerators and keep one of the denominators*/
    {
        result->numerator = (numerOne + numerTwo);
        result->denominator = denomOne;
    }
    else/*Else, follow fraction rules to add (find common denominator, multiply numerators, add)*/
    {
        finalNumer = (numerOne * denomTwo) + (numerTwo * denomOne);
        largestCommonDenom = denomOne * denomTwo;

        result->numerator = finalNumer;
        result->denominator = largestCommonDenom;
    }   

    return result; 
}

/*
 * preconditions: two initialized fractions are passed in as parameters
 * postconditions: the two fractions are multiplied together and the result is placed in a new Fraction variable that is returned to the calling procedure
*/
Fraction * multiply(Fraction * fracOne, Fraction * fracTwo)
{
    Fraction * result = malloc(sizeof(Fraction));/*Allocate memory for final answer*/

    /*Initializing variables*/
    int numerOne, denomOne;
    int numerTwo, denomTwo;
    int finalNumer;
    int finalDenom;

    /*Getting the numerator for fraction 1 & 2*/
    numerOne = getNumerator(fracOne);
    denomOne = getDenominator(fracOne);

    numerTwo = getNumerator(fracTwo);
    denomTwo = getDenominator(fracTwo);

    /*Calculating result*/
    finalNumer = (numerOne * numerTwo);
    finalDenom = (denomOne * denomTwo);

    /*Storing the result into the struct*/
    result->numerator = finalNumer;
    result->denominator = finalDenom;

    return result;   
}

/*
 * preconditons: the parameter Fraction is initialized
 * postconditions: the fraction is destroyed and memory released if necessary
*/
void destroyFraction(Fraction * theFraction)
{
    /*Set the values in the struct to 0*/
    theFraction->numerator = 0;
    theFraction->denominator = 0;

    /*If the fraction is not NULL, free it*/
    if(theFraction != NULL)
    {
        free(theFraction);
    }
}
/*
 * preconditons: the parameters take 2 integers to 'compare'
 * postconditions: the function will find the GCD of the two integers and upon failure it will return an error code
*/
 /*PART 2 FUNCTION
  *This function is the first step to simplifying the fraction
  */
int GCD(int num1, int num2)
{
    /*Initializing of variables*/
    int gcd;

    /*Change the values to a positive integer*/
    num1 = abs(num1);
    num2 = abs(num2);

    gcd = num1;/*equal the greatest common denominator to one of the numbers*/

    /*Get the largest value of the 2*/
    if(gcd < num2)
    {
        gcd = num2;
    }
    
    /*Continue until the remainder is 0, thats when you found the GCD*/
    while(gcd != 0)
    {
        if(num1 % gcd == 0 && num2 % gcd == 0)
        {
            return gcd;
        }  
        gcd--;
    }

    return -1; /*Return on failure*/
}

/*PART 2
 * preconditons: the parameters takes an initialized fraction
 * postconditions: the fraction gets simplified into its lowest terms

 Answer to Part 2: To make this program follow the definition of a fraction for part 2 because it simplifies the
 fraction to its lowest terms.
*/
void simplify(Fraction * theFraction)
{
    /*Initialize variables*/
    int findGCD;

    /*Call tje GCD function*/
    findGCD = GCD(theFraction->numerator, theFraction->denominator);

    /*Simplify the fraction*/
    theFraction->numerator = theFraction->numerator / findGCD;
    theFraction->denominator = theFraction->denominator / findGCD;
}

/*
 * preconditons: the parameters take an initialized fraction
 * postconditions: the function will print the fraction based on the criteria it fufills
*/
void printFraction(Fraction * toPrint)
{
    /*Intialize the variable*/
    int result;

    if(toPrint->denominator == 1) /*if the denominator is one, then just print out the numerator*/
    {
        printf("%d\n", toPrint->numerator);
    }
    else if(toPrint->numerator == toPrint->denominator)/*if the numerator equals the denominator, print out 1*/
    {
        result = toPrint->numerator / toPrint->denominator;
        printf("%d\n", result);
    }
    else if(toPrint->numerator == 0)/*if the numerator is 0, the result should be 0*/
    {
        result = 0 / 1;
        printf("%d\n", result);
    }
    else if(toPrint->denominator < 0)/*if the denominator is a negative, then the numerator should take the negative*/
    {
        toPrint->denominator = -(toPrint->denominator);
        toPrint->numerator = -(toPrint->numerator);
        printf("%d/%d\n", toPrint->numerator, toPrint->denominator);

    }
    else/*else, just print out the fraction*/
    {
        printf("%d/%d\n", toPrint->numerator, toPrint->denominator);
    }
}

