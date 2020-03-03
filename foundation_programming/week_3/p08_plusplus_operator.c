/*****************************************
 * p08_plusplus_operator.c
 * Demonstrate difference between num++ and ++num
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>

int main(void)
{
	int i;
	int num = 0;
	printf("num is: %d\n\n", num);
	
	for(i = 0; i <= 10; i++)
	{
		printf("num++: %d\n", num++);
	}
	
	num = 0;
	printf("\n\nnum is: %d\n\n", num);	
	
	for(i = 0; i <= 10; i++)
	{
		printf("++num: %d\n", ++num);
	}
	
	return 0;
}
