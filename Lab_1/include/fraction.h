/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: To declare libraries, structs and functions for the Fraction ADT
 *LAST MODIFICATION: May 15, 2014
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Fraction struct used for this ADT*/
typedef struct{
    int numerator;
    int denominator;
}Fraction;

/*Description:
 *Creates the fraction
 *Parameters:
 *numer: the numerator
 *denom: the denominator
 *Return:
 *Returns the struct with the new information in it
 */
Fraction * createFraction (int numer, int denom);

/*Description:
 *gets the numerator
 *Parameters:
 *theFraction: the initialized fraction
 *Return:
 *The numerator that was previously stored
 */
int getNumerator(Fraction * theFraction);

/*Description:
 *gets the denominator
 *Parameters:
 *theFraction: the initialized fraction
 *Return:
 *The denominator that was previously stored
 */
int getDenominator(Fraction * theFraction);

/*Description:
 *Adds two fractions together
 *Parameters:
 *fracOne: the first initialized fraction
 *fracTwo: the second initialized fraction
 *Return:
 *Returns the struct with the added fraction values stored
 */
Fraction * add(Fraction * fracOne, Fraction * fracTwo);

/*Description:
 *Multiplies two fractions together
 *Parameters:
 *fracOne: the first initialized fraction
 *fracTwo: the second initialized fraction
 *Return:
 *Returns the struct with the multiplied fraction values stored
 */
Fraction * multiply(Fraction * fracOne, Fraction * fracTwo);

/*Description:
 *Destroys the fraction (free the memory)
 *Parameters:
 *theFraction: the initialized fraction
 *Return:
 *No return, function is void
 */
void destroyFraction(Fraction * theFraction);

/*Description:
 *Finds the greatest common denominator of 2 integers
 *Parameters:
 *num1: the first integer value
 *num2: the second integer value
 *Return:
 *Returns the greatest common denominator found
 */
int GCD(int num1, int num2);

/*Description:
 *Simplifies the fractions to its lowest terms
 *Parameters:
 *theFraction: the initialized fraction
 *Return:
 *No return, function is void
 */
void simplify(Fraction * theFraction);

/*Description:
 *Prints out the fraction based on the condition it meets
 *Parameters:
 *toPrint: the initialized fraction that will be printed
 *Return:
 *No return, function is void
 */
void printFraction(Fraction * toPrint);