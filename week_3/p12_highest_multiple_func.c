/*****************************************
 * p12_highest_multiple_func.c
 * Write a program to print the highest multiple
 * of the given factor, using a func
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>

void highestMultiple(int num, int factor);
int rounded(int number, int factor);

int main(void)
{
	highestMultiple(365, 7);
	highestMultiple(12258, 23);
	highestMultiple(996, 4);
	
	printf("\n");
	
	return 0;

}

void highestMultiple(int num, int factor)
{
	int highestMultiple = rounded(num, factor);
	printf("Highest multiple of %d given factor %d is: %d\n", num, factor, highestMultiple);
}

int rounded(int number, int factor)
{
	return number - (number % factor);
}

