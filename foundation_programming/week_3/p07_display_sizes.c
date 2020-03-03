/*****************************************
 * p07_display_sizes.c
 * Show sizes of data types
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>

void displaySize(char type[], float size);

int main(void)
{
	displaySize("char", sizeof(char));
	displaySize("int", sizeof(int));
	displaySize("float", sizeof(float));
	displaySize("double", sizeof(double));
	displaySize("_Bool", sizeof(_Bool));
	displaySize("long int", sizeof(long int));
	displaySize("long long int", sizeof(long long int));
	displaySize("short int", sizeof(short int));
	displaySize("unsigned int", sizeof(unsigned int));
	displaySize("unsigned long int", sizeof(unsigned long int));
	displaySize("long double", sizeof(long double));
	
	return 0;
}

void displaySize(char type[], float size)
{
	printf("The size of %s is: %g bytes\n", type, size);
}
