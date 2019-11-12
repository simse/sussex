/* *********************************
 * p02_alter_names.c
 * A program to enter and display 10 names
 * Simon Sorensen
 * 12/11/19
 * *********************************/

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 75

int main(void)
{
    char names[10][MAX_NAME_LENGTH];
    printf("Brother, please enter 10 names.\n\n");
    for(int i = 0; i < 10; i++)
    {
        printf("\nPlease enter name %2d: ", i + 1);
        char tmp[MAX_NAME_LENGTH];
        fflush(stdin);
        fgets(tmp, MAX_NAME_LENGTH, stdin);
        tmp[strlen(tmp)-1] = '\0';
        strcpy(names[i], tmp);
    }

    puts("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%s\n", names[i]);
    }

    /* Alter names */

}