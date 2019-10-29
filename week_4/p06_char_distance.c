/* *********************************
 * p06_char_distance.c
 * 
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int calculateCharDistance(char char1, char char2);
void clearBuffer(void);

int main(void)
{
	char char1, char2;
	
	
	while(1)
	{
		printf("Please enter your first character: ");
		scanf("%c", &char1);
		
		if(char1 == '\n')
		{
			break;
		}
		clearBuffer();
		printf("Please enter your second character: ");
		scanf("%c", &char2);
		if(char1 == '\n')
		{
			break;
		}
		clearBuffer();
		printf("\nThe distance between %c and %c is: %d\n\n\n", char1, char2, calculateCharDistance(char1, char2));
	}
	
	printf("\nBye now!");
}

int calculateCharDistance(char char1, char char2)
{
	return char2 - char1 - 1;
}

void clearBuffer(void)
{
	while(getchar() != '\n')
	{
		;
	}
}
