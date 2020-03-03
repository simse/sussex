#include <stdio.h>

int main(void)
{
    char string[10];

    gets(&string);

    printf("%s", string);
}