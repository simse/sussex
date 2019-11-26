/* *********************************
 * p04_average.c
 * A function to find the average
 * Simon Sorensen
 * 12/11/19
 * *********************************/

#include <stdio.h>
#include <string.h>

int average(double numbers[], int numOfNums);

int main(void)
{
    double numbers[] = {1,2,3,4};
    printf("The average is: %d", average(numbers, 4));

    return 0;
}

int average(double numbers[], int numOfNums)
{
    double average;
    for(int i = 0; i < numOfNums; i++)
    {
        average += numbers[i];
    }

    return average / (double)numOfNums;
}