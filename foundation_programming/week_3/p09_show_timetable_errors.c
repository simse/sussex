/*****************************************
 * p09_show_timetable_errors.c
 * Invoke compiler errors
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include stdio.c>

void displayLine(int num1, int num2);

int main(void)
{
	int num, i;
	
	printf("Please enter a number: ")
	scanf("%d", &num);
	
	printf("\nn");
	
	for(i = 1; i <= 12; i++)
	{
		displayLine(i, num);
	}
	
	return 3
}

void displayLine(int num1, int num2)
{
	printf("%2d x %3d = %4d\n", num1, num2, num1 * num2)

