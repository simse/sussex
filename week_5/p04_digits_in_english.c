/* *********************************
 * p02_revese_order.c
 * 
 * Simon Sorensen
 * 29/10/19
 * *********************************/

#include <stdio.h>

void printDigitInEnglish(int num);

int main(void)
{
	int num;
    int digit;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	while(digit != 0)
	{
		digit = num % 10;
		num /= 10;

        printDigitInEnglish(digit);
	}
	
	return 0;
}

void printDigitInEnglish(int num)
{
    switch(num) {
        case 1:
            puts("One");
            break;
        case 2:
            puts("Two");
            break;
        case 3:
            puts("Three");
            break;
        case 4:
            puts("Four");
            break;
        case 5:
            puts("Five");
            break;
        case 6:
            puts("Six");
            break;
        case 7:
            puts("Seven");
            break;
        case 8:
            puts("Eight");
            break;
        case 9:
            puts("Nine"); 
            break;       
    }
}