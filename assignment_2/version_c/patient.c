#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "patient.h"
#include "encrypt.h"

#define MAX_COMMENTS 50
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

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
    do
    {
        printf("Enter first name: ");
        scanf("%[^\n]", patient->first_name);
        getchar();
    } while (strlen(patient->first_name) == 0);
    do
    {
        printf("\nEnter last name: ");
        scanf("%[^\n]", patient->last_name);
        getchar();
    } while (strlen(patient->last_name) == 0); 
}

void getBodyMeasurements(struct patient *patient)
{
    _Bool error = 0;
    do
    {
        if(error) puts(RED "Error - height out of range!" RESET);
        printf("\nEnter patient height (cm): ");
        scanf("%d%*c", &patient->height);
        error = 1;
    } while(patient->height < 100 || patient->height > 280);
    fflush(stdin);
    error = 0;
    do
    {
        if(error) puts(RED "Error - waist out of range!" RESET);
        printf("\nEnter patient waist (cm): ");
        scanf("%d%*c", &patient->waist);
        error = 1;
    } while (patient->waist < 20 || patient->waist > 200);
    fflush(stdin);
    error = 0;
    do
    {
        if(error) puts(RED "Error - weight out of range!" RESET);
        printf("\nEnter patient weight (kg): ");
        scanf("%d%*c", &patient->weight);
        error = 1;
    } while(patient->weight < 20 || patient->weight > 500);
}

void getComments(struct patient *patient)
{
    char confirm = 'n';
    int count = 0;
    do
    {
        printf("\nWould you like to add any comments? (y/n): ");
        scanf("%c%*c", &confirm);
        fflush(stdin);
        count++;
    } while (confirm == 'y' && getComment(patient, count - 1));
}

_Bool getComment(struct patient *patient, int index)
{
    char comment[3000];
    fflush(stdin);
    printf("\nEnter comment: ");
    scanf("%[^\n]%*c", &comment);
    strcpy(patient->comment[index], comment);
    printf("Comment added!\n");

    return 1;
}

void savePatient(struct patient patient)
{
    char filename[120];
    sprintf(filename, "patients/%s%02d%02d%02d.aow", patient.last_name,
            patient.birthday, patient.birthmonth, patient.birthyear);
    FILE *patientFile;
    patientFile = fopen(filename, "w");
    fprintf(patientFile, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
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

_Bool openPatient(char filename[], struct patient *patient)
{
    FILE *patientFile;
    char file[255];
    sprintf(file, "patients/%s", filename);
    patientFile = fopen(file, "r");
    if(!patientFile)
    {
        printf(RED "File not found!\n" RESET);
        return 0;
    }
    char buffer[255];
    fscanf(patientFile, "%s", buffer);
    strcpy(patient->first_name, decrypt(buffer, 255));
    fscanf(patientFile, "%s", buffer);
    strcpy(patient->last_name, decrypt(buffer, 255));
    fgets(buffer, sizeof buffer, patientFile);
    fgets(buffer, sizeof buffer, patientFile);
    patient->birthday = decryptNum(buffer);
    fgets(buffer, sizeof buffer, patientFile);
    patient->birthmonth = decryptNum(buffer);
    fgets(buffer, sizeof buffer, patientFile);
    patient->birthyear = decryptNum(buffer);
    fgets(buffer, sizeof buffer, patientFile);
    patient->height = decryptNum(buffer);
    fgets(buffer, sizeof buffer, patientFile);
    patient->waist = decryptNum(buffer);
    fgets(buffer, sizeof buffer, patientFile);
    patient->weight = decryptNum(buffer);
    int i = 0;
    while (fgets(buffer, sizeof buffer, patientFile) != NULL)
    {
        strcpy(patient->comment[i - 1], decrypt(buffer, 2000));
        i++;
    }
    fclose(patientFile);
    return 1;
}

void row(int columnSize, char columnName[], char columnContents[])
{
    printf("| %-8s | %-*s |", columnName, columnSize - 1, columnContents);
}

void showPatient(struct patient patient)
{
    /* Generate correct divider */
    int maxColumnWidth = strlen(patient.first_name) + strlen(patient.last_name) + 2;
    char divider[60];
    strcpy(divider, "\n+----------+");
    for (int i = 0; i < maxColumnWidth + 1; i++)
    {
        strcat(divider, "-");
    }
    strcat(divider, "+");
    /* Print out table */
    puts(divider);
    char name[60];
    sprintf(name, "%s %s", patient.first_name, patient.last_name);
    row(maxColumnWidth, "Name", name);
    puts(divider);
    char weight[10];
    sprintf(weight, "%dkg", patient.weight);
    row(maxColumnWidth, "Weight", weight);
    puts(divider);
    char height[10];
    sprintf(height, "%dcm", patient.height);
    row(maxColumnWidth, "Height", height);
    puts(divider);
    char waist[10];
    sprintf(waist, "%dcm", patient.waist);
    row(maxColumnWidth, "Waist", waist);
    puts(divider);
    char birthday[20];
    sprintf(birthday, "%02d/%02d/%02d", patient.birthday, patient.birthmonth, patient.birthyear);
    row(maxColumnWidth, "Birthday", birthday);
    puts(divider);

    // TODO: Show comments
}

void editPatient(struct patient *patient)
{
    puts("You can edit:");
    puts("- 1: Name");
    puts("- 2: Body measurements");
    puts("- 3: Birthday\n");
    printf("What would you like to edit? ");
    int toEdit;
    scanf("%d%*c", &toEdit);
    if(toEdit == 1) getName(patient);
    if(toEdit == 2) getBodyMeasurements(patient);
    if(toEdit == 3) getBirthday(patient, 8);
    savePatient(*patient);
}

void listPatients(struct patient *patients, int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("- %d: %s %s\n", i + 1, patients[i].first_name, patients[i].last_name);
    }
}