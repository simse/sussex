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

#include "encrypt.h"

#define FILE_BUFFER 55
#define MAX_COMMENTS 10
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

/* Structures */
struct nurse
{
    char name[50];
    char id[9];
    char password[9];
};

struct patient
{
    char first_name[50];
    char last_name[50];
    int birthday;
    int birthmonth;
    int birthyear;
    int height;
    int waist;
    int weight;
    char comment[MAX_COMMENTS][2000];
};

/* Main functions */
void loadAuth(struct nurse nurses[]);
_Bool validateCredentials(char *id, char *password, struct nurse nurses[]);
void login(struct nurse nurses[]);
void savePatient(struct patient patient);

/* Data input */
int getNumber(int min, int max);
void showError(char message[], int line, int column);
void birthdayInputError(int day, int month, int year, int line);
void getBirthday(struct patient *patient, int displayLine);
void getName(struct patient *patient);
void getBodyMeasurements(struct patient *patient);
void getComments(struct patient *patient);
_Bool getComment(struct patient *patient, int index);

/* Utility functions */
void clearScreen(void);

int main(void)
{
    struct nurse nurses[5];
    struct patient patient;
    loadAuth(nurses);
    login(nurses); //Username = a2345678, password =
    clearScreen();
    puts("Welcome to the patient management system 5000");
    printf("Would you like to add a patient? (y/n): ");
    char confirm;
    scanf("%c%*c", &confirm);

    if (confirm == 'n')
    {
        puts("\nSo why'd you open the program then fool?");
    }
    else
    {
        getName(&patient);
        getBirthday(&patient, 7);
        getBodyMeasurements(&patient);
        getComments(&patient);
        savePatient(patient);
        puts("To add another patient, execute: ./nurse");
    }
    return 0;
}

void loadAuth(struct nurse nurses[])
{
    FILE *auth;
    char tmp[FILE_BUFFER];
    auth = fopen("auth.txt", "r");
    for (int nurse = 0; nurse < 5; nurse++)
    {
        for (int field = 0; field < 3; field++)
        {
            fgets(tmp, FILE_BUFFER, (FILE *)auth);
            strtok(tmp, "\n");
            strcpy(tmp, decrypt(tmp, FILE_BUFFER));
            if (field == 0)
            {
                strcpy(nurses[nurse].name, tmp);
            }
            if (field == 1)
            {
                strcpy(nurses[nurse].id, tmp);
            }
            if (field == 2)
            {
                strcpy(nurses[nurse].password, tmp);
            }
        }
    }
    fclose(auth);
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
    //clearScreen();
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

void savePatient(struct patient patient)
{
    char filename[120];
    sprintf(filename, "patients/%s%02d%02d%02d.aow", patient.last_name,
            patient.birthday, patient.birthmonth, patient.birthyear);
    FILE *patientFile;
    patientFile = fopen(filename, "w");
    fprintf(patientFile, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n",
            encrypt(patient.first_name, 50),
            encrypt(patient.last_name, 50),
            encryptNum(patient.birthday),
            encryptNum(patient.birthmonth),
            encryptNum(patient.birthyear),
            encryptNum(patient.height),
            encryptNum(patient.waist),
            encryptNum(patient.weight));
    for (int i = 0; i < 10; i++)
    {
        fprintf(patientFile, "%s\n", encrypt(patient.comment[i], 3000));
    }
    fclose(patientFile);
    printf(GREEN "\nSaved patient to file: %s!\n\n" RESET, filename);
}

/* Input functions */
void showError(char message[], int line, int column)
{
    printf(RED "\033[%d;%dH^^ %s" RESET, line, column, message);
}

void birthdayInputError(int day, int month, int year, int line)
{
    if (day < 1 || day > 31)
    {
        showError("Inputted day must be between 1 and 31",
                  line + 1, 28);
    }
    if (month < 1 || month > 12)
    {
        showError("Inputted month must be between 1 and 12",
                  line + 1, 31);
    }
    if (year < 1 || year > 99)
    {
        showError("Inputted year must be between 1900 and now",
                  line + 1, 34);
    }
}

void getBirthday(struct patient *patient, int displayLine)
{
    int day = 1;
    int month = 1;
    int year = 1;
    do
    {
        birthdayInputError(day, month, year, displayLine);
        printf("\033[%d;0HEnter birthday (DD/MM/YY): __/__/__          "
               "\033[%d;28H",
               displayLine, displayLine);
    } while (scanf("%d/%d/%d", &day, &month, &year) != 3 || day < 1 ||
             day > 31 || month < 1 || month > 12 || year < 1 ||
             year > 99);
    patient->birthday = day;
    patient->birthmonth = month;
    patient->birthyear = year;
}

void getName(struct patient *patient)
{
    printf("Enter first name: ");
    scanf("%[^\n]%*c", patient->first_name);
    printf("\nEnter last name: ");
    scanf("%[^\n]%*c", patient->last_name);
}

void getBodyMeasurements(struct patient *patient)
{
    printf("\nEnter patient height (cm): ");
    scanf("%d", &patient->height);
    fflush(stdin);
    printf("\nEnter patient weight (kg): ");
    scanf("%d", &patient->weight);
    fflush(stdin);
    printf("\nEnter patient waist (cm): ");
    scanf("%d", &patient->waist);
    fflush(stdin);
}

void getComments(struct patient *patient)
{
    char confirm;
    int count = 0;
    do
    {
        printf("\nWould you like to add any comments? (y/n): ");
        fflush(stdin);
        scanf("%c%*c", &confirm);
        count++;
    } while (confirm == 'y' && getComment(patient, count - 1));
}

_Bool getComment(struct patient *patient, int index)
{
    char comment[3000];
    printf("\nEnter comment: ");
    scanf("%[^\n]", &comment);
    getchar();
    strcpy(patient->comment[index], comment);
    printf("Comment added!\n");
    return 1;
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