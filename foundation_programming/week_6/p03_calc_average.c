/* *********************************
 * p03_calc_average.c
 * A program to calculate the average of a sequence
 * Simon Sorensen
 * 29/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int total = 0;
    int count = -1;
    int current = 0;
    
    while(current != 9999)
    {
        count++;
        total += current;

        printf("Enter a number: ");
        scanf("%d", &current);

        fflush(stdin);
    }

    printf("\n\nThe average is: %d", total / count);

	return 0;
}
