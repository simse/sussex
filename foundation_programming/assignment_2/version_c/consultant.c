/***********************************************************************
 * consultant.c
 * A program to view and edit patient details
 * Simon Sorensen
 * 21/11/19
 * Version c
 * ********************************************************************/

#include <stdio.h>
#include "constants.h"
#include "patient.h"
#include "encrypt.h"
#include "nurse.h"
#include "auth.h"

void editNurseCredentials(void);
void addNurse(void);
void deleteNurse(void);
void displayOptions(void);
void wait(void);
void clearScreen(void);
_Bool verifyLogin(char username[], char password[]);
void getPatient(struct patient *patient);

int main(void)
{
    consultantLogin();
    clearScreen();
    int option;
    struct patient patient;
    while (option != 6)
    {
        displayOptions();
        printf("\n\nPlease enter an option: ");
        scanf("%d%*c", &option);
        if(option == 6)
        {
            exit(0);
        }
        
        if(option == 1 || option == 2)
        {
            getPatient(&patient);
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
            editNurses();
        }
        if(option == 4)
        {
            deleteNurse();
        }
        if(option == 5)
        {
            addNurse();
        }
        wait();
        clearScreen();
    }
    return 0;
}

void getPatient(struct patient *patient)
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
    } while(!openPatient(filename, patient));
}



void displayOptions(void)
{
    puts("Welcome! The menu options are:\n");
    puts("1. View patient");
    puts("2. Edit patient");
    puts("3. Edit nurse passwords");
    puts("4. Delete a nurse");
    puts("5. Add a nurse");
    puts("6. Exit");
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