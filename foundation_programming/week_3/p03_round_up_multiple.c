/*****************************************
 * p03_round_up_multiple.c
 * Round up integer n to the next large
 * multiple m
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>

int nextMultiple(int num, int multiple);

int main(void)
{
	int num, multiple;
	
	printf("%s", "Please enter a number: ");
	scanf("%d", &num);
	
	printf("%s", "Please enter a multiple: ");
	scanf("%d", &multiple);
	
	printf("\nRounding up, the next multiple for %d is: %d", num, nextMultiple(num, multiple));
	
	return 0;
}

int nextMultiple(int num, int multiple)
{
	return num + multiple - num % multiple;
}
