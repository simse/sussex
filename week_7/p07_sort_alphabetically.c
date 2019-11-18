/* *********************************
 * p07_sort_alphabetically.c
 * A program to enter and display 10 names sorted alphabetically
 * Simon Sorensen
 * 18/11/19
 * *********************************/

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 75
#define NAMES 10

void displayNames(char names[NAMES][MAX_NAME_LENGTH]);
void enterNameForId(char name[MAX_NAME_LENGTH], int index);
void sortByFirstLetter(char names[NAMES][MAX_NAME_LENGTH]);

int main(void)
{
    char names[NAMES][MAX_NAME_LENGTH];
    printf("Brother, please enter 10 names.\n\n");
    for(int i = 0; i < 10; i++)
    {
        enterNameForId(names[i], i);
    }


    sortByFirstLetter(names);
    displayNames(names);

    /* */

    /* Alter names 
    int alterId = 0;
    do
    {
        printf("\nWhich name would you like to alter (press 0 to exit)? ");
        scanf("%d", &alterId);
        if(alterId == 0 || alterId > 10) continue;
        fflush(stdin);
        enterNameForId(names, alterId - 1);
        displayNames(names);
    } while(alterId != 0);*/
}

void displayNames(char names[NAMES][MAX_NAME_LENGTH])
{
    puts("\n");
    for(int i = 0; i < NAMES; i++)
    {
        printf("(%d) %s\n", i+1, &names[i]);
    }
}

void enterNameForId(char name[MAX_NAME_LENGTH], int index)
{
    printf("\nPlease enter name %2d: ", index + 1);
    char tmp[MAX_NAME_LENGTH];
    fflush(stdin);
    fgets(tmp, MAX_NAME_LENGTH, stdin);
    tmp[strlen(tmp)-1] = '\0';
    strcpy(name, tmp);
}

void sortByFirstLetter(char names[NAMES][MAX_NAME_LENGTH])
{
    _Bool hasChanged = 1;
    while(hasChanged == 1)
    {
        hasChanged = 0;        

        for(int i = 0; i < NAMES; i++)
        {
            if(i == 0)
            {
                continue;
            } else {
                if(names[i-1][0] > names[i][0])
                {
                    char tmp[MAX_NAME_LENGTH];
                    strcpy(tmp, names[i-1]);
                    strcpy(names[i-1], names[i]);
                    strcpy(names[i], tmp);
                    hasChanged = 1;
                }
            }
        }
    }
}