/***********************************************************************
 * consultant.c
 * A program to view and edit patient details
 * Simon Sorensen
 * 21/11/19
 * Version c
 * ********************************************************************/

#include <stdio.h>
#include "patient.h"
#include "encrypt.h"
#include "nurse.h"
#include "auth.h"

#define ASCII_NUMBER_LOWER_BOUND 47
#define ASCII_NUMBER_UPPER_BOUND 58
#define ASCII_LOWERCASE_LOWER_BOUND 64
#define ASCII_LOWERCASE_UPPER_BOUND 91
#define ASCII_UPPERCASE_LOWER_BOUND 96
#define ASCII_UPPERCASE_UPPER_BOUND 123

void editNurseCredentials(void);
void addNurse(void);
void deleteNurse(void);
void displayOptions(void);
void wait(void);
void clearScreen(void);
_Bool verifyLogin(char username[], char password[]);
_Bool verifyFormat(char input[]);

int main(void)
{
    int option;
    struct patient patient;
    while (option != 4)
    {
        displayOptions();
        printf("\n\nPlease enter an option: ");
        scanf("%d%*c", &option);
        if(option == 4)
        {
            exit(0);
        }
        int patientNumber;
        if(option == 1 || option == 2)
        {
            char lastname[55];
            char filename[255];
            do {
                printf("\nEnter patient lastname: ");
                scanf("%s%*c", lastname);
                int birthday;
                printf("Enter birthday (DDMMYY): ");
                scanf("%d%*c", &birthday);
                sprintf(filename, "%s%d.aow", lastname, birthday);
            } while(!openPatient(filename, &patient));
        }
        if(option == 1)
        {
            showPatient(patient);
        }
        if(option == 2)
        {
            clearScreen();
            editPatient(&patient);
        }
        if(option == 3)
        {
            editNurseCredentials();
        }
        wait();
        clearScreen();
    }
}

void editNurseCredentials(void)
{
    struct nurse nurses[5];
    loadAuth(nurses);
    puts("The nurses are:");
    for(int i = 0; i < 10; i++)
    {
        printf("- %d: %s\n", i + 1, nurses[i].name);
    }
    int nurse = 0;
    do {
        printf("\nWhich nurse credentials you like to update? ");
        scanf("%d%*c", &nurse);
    } while(nurse < 0 && nurse > 10);
    char username[9], password[9];
    do
    {
        printf("\nNew username: ");
        scanf("%[^\n]", &username);
        getchar();
    } while (!verifyFormat(username));
    do
    {
        printf("\nNew password: ");
        scanf("%[^\n]", &password);
        getchar();
    } while (!verifyFormat(password));
    strcpy(nurses[nurse-1].id, username);
    strcpy(nurses[nurse-1].password, password);
    saveAuth(nurses);
    printf("\n\nCredentials saved!");
}

void addNurse(void)
{

}

void deleteNurse(void)
{
    struct nurse nurses[5];
    loadAuth(nurses);
    puts("The nurses are:");
    for(int i = 0; i < 10; i++)
    {
        printf("- %d: %s\n", i + 1, nurses[i].name);
    }
    int nurse = 0;
    do {
        printf("\nWhich nurse credentials you like to delete? ");
        scanf("%d%*c", &nurse);
    } while(nurse < 0 && nurse > 10);
}

_Bool verifyFormat(char input[])
{
    if(strlen(input) != 8)
    {
        puts("IDs and passwords must be 8 characters in length!");
        return 0;
    }
    if(!(
        (input[0] > ASCII_LOWERCASE_LOWER_BOUND && 
            input[0] < ASCII_LOWERCASE_UPPER_BOUND) || 
        (input[0] > ASCII_UPPERCASE_LOWER_BOUND &&
            input[0] < ASCII_UPPERCASE_UPPER_BOUND)))
    {
        puts("IDs and password must start with a letter!");
        return 0;
    }
    for(int i = 0; i < strlen(input); i++)
    {
        if(
            !((input[i] > ASCII_LOWERCASE_LOWER_BOUND && 
                input[i] < ASCII_LOWERCASE_UPPER_BOUND)  ||
            (input[i] > ASCII_UPPERCASE_LOWER_BOUND &&
                input[i] < ASCII_UPPERCASE_UPPER_BOUND) ||
            (input[i] > ASCII_NUMBER_LOWER_BOUND &&
                input[i] < ASCII_NUMBER_UPPER_BOUND)))
        {
            puts("IDs and passwords must be alphanumeric!");
            return 0;
        }
    }
    return 1;
}

void displayOptions(void)
{
    puts("Welcome! The menu options are:\n");
    puts("1. View patient");
    puts("2. Edit patient");
    puts("3. Edit nurse passwords");
    puts("4. Exit");
}

void wait(void)
{
    fflush(stdin);
    printf("\nPress ENTER to continue...");
    getchar();
}

void clearScreen(void)
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}