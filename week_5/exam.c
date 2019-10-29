#include <stdio.h>

int main(void)
{
    int row;

    for(row = 1; row <= 9; row++)
    {
        int column;

        for(column = 1; column <= row; column++)
        {
            printf("%d ", row);
        }

        printf("\n");
    }
}