/*****************************************
 * p10_evaluate_expression.c
 * Evaluate a long expression and print it
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>
#include <math.h>

double equation(void);

int main(void)
{
	printf("The answer is: %e", equation());
	
	return 0;
}

double equation(void)
{
	
	return (3.31 * pow(10, -8) * 2.01 * pow(10, -7)) / (7.16 * pow(10, -6) + 2.01 * pow(10, -8));
}
