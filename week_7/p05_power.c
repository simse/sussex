/* *********************************************************************
 * p05_power.c
 * A function to raise number x to the power p
 * Simon Sorensen
 * 18/11/19
 * ********************************************************************/

#include <stdio.h>
#include <string.h>

double power(double x, int p);

int main(void)
{
    printf("20^4 is: %g\n", power(20.0, 4));
    printf("5.24^10 is: %f\n", power(5.24, 10));

    return 0;
}

double power(double x, int p) {
    double result = x;

    for(int i = 0; i < p - 1; i++)
    {
        result = result * x;
    }

    return result;
}