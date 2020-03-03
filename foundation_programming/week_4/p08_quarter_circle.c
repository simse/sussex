/* *********************************
 * p08_quarter_circle.c
 * Honestly, not sure
 * Simon Sorensen
 * 22/10/19
 * *********************************/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int radius = 20;
	
	for(int x = 0; x <= radius; x++)
	{
		for(int y = 0; y <= radius; y++)
		{
			if(pow(x, 2) + pow(y, 2) < pow(radius, 2))
			{
				printf("* ");
			}
			
		}
		printf("\n");
	}
	
	return 0;
}
