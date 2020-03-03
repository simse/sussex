/* *********************************
 * p01_days_to_christmas.c
 * A program to calculate days to christmas
 * Simon Sorensen
 * 26/11/19
 * *********************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int day;
    int month;

    printf("Please enter a day: ");
    scanf("%d", &day);

    printf("Please enter a month: ");
    scanf("%d", &month);

    if(day == 24 && month == 12)
    {
        printf("It's today, Merry Christmas!");
    }

    if(month == 12 && day > 24)
    {
        printf("Aproximately %d days till Christmas, exicting!", day + 335);
    }
    else
    {
        printf("Aproximately %d days till Christmas, exicting!", (12 - month) * 31 + 24 - day);
    }

    puts("\n");
    return 0;
}