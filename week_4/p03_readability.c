/* *********************************
 * p03_readabilty.c
 * Fix the formatting of a program
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int n, powersOfTwo;
	printf("TABLE OF POWERS OF TWO\n\n");
	printf(" n     2 to the n\n");
	printf("===    =========\n");
	powersOfTwo = 1;
	for(n = 0; n <= 10; n++)
	{
		printf("%2d                %d\n", n, powersOfTwo *= 2);
	}
	
	printf("\n");
	return 0;
}
