/***********************************************************************
 * nurse.c
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

void editNurseCredentials(void);
void displayOptions(void);
void wait(void);
void clearScreen(void);

int main(void)
{
    int option;
    struct patient patient;
    while (option != 4)
    {
        displayOptions();

        printf("\n\nPlease enter an option: ");
        scanf("%d%*c", &option);

        if(option == 4) exit(0);

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

        if(option == 3) editNurseCredentials();

        wait();
        clearScreen();
    }
}

void editNurseCredentials(void)
{
    struct nurse nurses[5];
    loadAuth(nurses);

    puts("The nurses are:");
    for(int i = 0; i < 5; i++)
    {
        printf("- %d: %s\n", i + 1, nurses[i].name);
    }

    int nurse = 0;
    do {
        printf("\nWhich nurse credentials you like to update? ");
        scanf("%d%*c", &nurse);
    } while(nurse < 0 && nurse > 6);
    
    char username[9], password[9];
    printf("\nNew username: ");
    scanf("%[^\n]%*c", &username);
    printf("\nNew password: ");
    scanf("%[^\n]%*c", &password);
    strcpy(nurses[nurse-1].id, encrypt(username, 8));
    strcpy(nurses[nurse-1].password, encrypt(password, 8));
    saveAuth(nurses);
    printf("\n\nCredentials saved!");
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