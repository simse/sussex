/* *********************************
 * p01_square_loop.c
 * A program that prints the square
 * of all numbers between 1 and 20
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int i;
	for(i = 1; i <= 20; i++)
	{
		printf("The square of %d is %d\n", i, i*i);
	}
}
