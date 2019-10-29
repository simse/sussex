/* *********************************
 * p05_sum_digits.c
 * Sum of the digits in an integer
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int num;
	int total = 0;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	while(1)
	{
		int digit = num % 10;
		num /= 10;
		
		total += digit;
		
		if(num < 1)
		{
			break;
		}
	}
	
	printf("The total is: %d\n", total);
	
	return 0;
}
