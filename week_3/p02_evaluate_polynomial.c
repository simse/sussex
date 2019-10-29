/*****************************************
 * p02_evaluate_polynomial.c
 * Evaluate certain polynomial
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
 #include <stdio.h>
 
 float equation(float x);
 
 int main(void)
 {
 	printf("3x^3 - 5x^2 + 6, when x = 2.55 is equal to: %.3f", equation(2.55));
 	
 	return 0;
 }
 
 float equation(float x) 
 {
 	return 3 * (x * x * x) - 5 * (x * x) + 6;
 }
 
