/*****************************************
 * p12_evaluate_pow.c
 * Use pow() to evaluate equation
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>
#include <math.h>

float equation(float x);

int main(void)
{
	printf("19x^3 - 33x^2 + 15x - 17 = %g", equation(7.5));
	
	return 0;
}

float equation(float x)
{
	return 19 * pow(x, 3) - 33 * pow(x, 2) + 15 * x - 17;
}
