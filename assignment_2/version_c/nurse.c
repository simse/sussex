/***********************************************************************
 * nurse.c
 * A program to enter patient details to be saved and read later
 * Simon Sorensen
 * 21/11/19
 * Version c
 * ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "nurse.h"
#include "auth.h"
#include "encrypt.h"
#include "patient.h"


#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

/* Main functions */
_Bool validateCredentials(char *id, char *password, struct nurse nurses[]);
void login(struct nurse nurses[]);
void displayTitle();

/* Utility functions */
void clearScreen(void);

int main(void)
{
    struct nurse nurses[5];
    struct patient patient;
    loadAuth(nurses);
    login(nurses);
    clearScreen();
    displayTitle();
    puts("Add new patient:");
    getName(&patient);
    getBirthday(&patient, 10);
    getBodyMeasurements(&patient);
    getComments(&patient);
    savePatient(patient);
    puts("To add another patient, execute: ./nurse");
    return 0;
}

_Bool validateCredentials(char *id, char *password, struct nurse nurses[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(nurses[i].id, id) == 0 &&
            strcmp(nurses[i].password, password) == 0)
        {
            return 1;
        }
    }
    puts(RED "Wrong combination!\n" RESET);
    return 0;
}

void login(struct nurse nurses[])
{
    char username[9];
    char password[9];
    printf("Nurse terminal\n");
    do
    {
        printf("\nUsername: ");
        scanf("%[^\n]", username);
        getchar();
        printf("\nPassword: ");
        scanf("%[^\n]", password);
        getchar();
    } while (!validateCredentials(username, password, nurses));
}

void displayTitle()
{
    puts("/ ******************************************** /");
    puts("/            King's Royal Hospital             /");
    puts("/ ******************************************** /\n");
}

/* Utility functions */
void clearScreen(void)
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}