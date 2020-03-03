/* *********************************
 * p01_change.c
 * A program to calculate change
 * Simon Sorensen
 * 29/10/19
 * *********************************/

#include <stdio.h>

int main(void)
{
	int sizes[] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    const char *names[11];
    names[0] = "20 pounds";
    names[1] = "10 pounds";
    names[2] = "5 pounds";
    names[3] = "2 pounds";
    names[4] = "1 pound";
    names[5] = "50 pence";
    names[6] = "20 pence";
    names[7] = "10 pence";
    names[8] = "5 pence";
    names[9] = "2 pence";
    names[10] = "1 pence";

    int total_pence;
    int pounds;
    int pence;
    printf("Enter amount in pounds and pence (e.g. 2.50): ");
    scanf("%d.%d", &pounds, &pence);
    total_pence = pounds * 100 + pence;

    int coin_table_length = sizeof(sizes) / sizeof(int);
    for(int i = 0; i < coin_table_length; i++)
    {
        int count = total_pence / sizes[i];
        total_pence -= count * sizes[i];

        printf("%s: %d\n", names[i], count);
    }

	return 0;
}
