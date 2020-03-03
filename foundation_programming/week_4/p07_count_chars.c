/* *********************************
 * p07_count_chars.c
 * Counts characters until return key
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int count;
	
	while(getchar() != '\n')
	{
		count++;
	}
	
	printf("You have entered %d characters!\n", count);
	
	return 0;
}
