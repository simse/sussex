#include <stdio.h>

int main(void)
{
    int num1, num2;

    printf("Please enter number 1: ");
    scanf("%d", &num1);

    printf("Please enter number 2: ");
    scanf("%d", &num2);

    if(num1 % num2 == 0)
    {
        printf("\n%d is evenly divisble by %d\n", num1, num2);
    } else 
    {
        printf("\n%d is NOT evenly divisble by %d\n", num1, num2);
    }
}