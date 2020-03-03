/* *********************************
 * p02_triangle_numbers.c
 * A program that prints the triangle
 * of all numbers between 5 and 50
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int i;
	for(i = 5; i <= 50; i += 5)
	{
		printf("Triangle of %d is: %d\n", i, i * (i+1) / 2);
	}
}
