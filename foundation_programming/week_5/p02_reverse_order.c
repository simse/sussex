/* *********************************
 * p02_revese_order.c
 * 
 * Simon Sorensen
 * 29/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int num;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	while(1)
	{
		int digit = num % 10;
		num /= 10;
		
		if(digit == 0)
		{
			break;
		}

        printf("%d", digit);
	}
	
	return 0;
}
