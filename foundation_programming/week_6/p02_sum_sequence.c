/* *********************************
 * p02_sub_sequence.c
 * A program to sum up a sequence of numbers
 * Simon Sorensen
 * 29/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int numbers = 0;
    int sum = 0;
    printf("How many numbers? ");
    scanf("%d", &numbers);

    for(int i = 0; i < numbers; i++)
    {
        int temp = 0;
        printf("Enter number: ");
        scanf("%d", &temp);
        sum += temp;
    }

    printf("\n\nThe sum is: %d", sum);

	return 0;
}
