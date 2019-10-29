/*****************************************
 * p14_quadratic_formula.c
 * Write a quadratic formular
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
#include <stdio.h>
#include <math.h>

double quadroot(double a, double b, double c);

int main(void)
{
	printf("a = 2, b = 1, c = -6 is equal to: %g\n", quadroot(2, 1, -6));
	
	return 0;
}

double quadroot(double a, double b, double c)
{
	double forS = pow(b, 2) - (4 * a * c);
	return (-b + sqrt(forS)) / (2 * a);
}
