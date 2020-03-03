/* *********************************
 * p04_factorial.c
 * Calculate first 10 factorials
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int factorial(int num);

int main(void)
{
	int i;
	for(i = 1; i <= 10; i++)
	{
		printf("!%d = %d\n", i, factorial(i));
	}
	
	return 0;
}

int factorial(int num)
{
 	if(num == 0)
 	{
 		return 1;
    }
	
	return num * factorial(num - 1);
}
