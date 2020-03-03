/* *********************************
 * p03_max.c
 * A function to find the largest number
 * Simon Sorensen
 * 12/11/19
 * *********************************/

#include <stdio.h>
#include <string.h>

int max(int num1, int num2);

int main(void)
{
    printf("The largest number is: %d\n", max(20, 43));
    printf("The largest number is: %d\n", max(99, 100));
    printf("The largest number is: %d\n", max(1, 2));
    printf("The largest number is: %d\n", max(0, 3));
    printf("The largest number is: %d\n", max(20303030, 2208402830283));
    printf("The largest number is: %d\n", max(21312320, 43));

    return 0;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}