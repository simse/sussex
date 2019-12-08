#include <stdlib.h>

#pragma once

#define MAX_COMMENTS 50

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

int getNumber(int min, int max);
void showError(char message[], int line, int column);
void birthdayInputError(int day, int month, int year, int line);
void getBirthday(struct patient *patient, int displayLine);
void getName(struct patient *patient);
void getBodyMeasurements(struct patient *patient);
void getComments(struct patient *patient);
_Bool getComment(struct patient *patient, int index);
void savePatient(struct patient patient);
_Bool openPatient(char filename[], struct patient *patient);
void row(int columnSize, char columnName[], char columnContents[]);
void showPatient(struct patient patient);
void editPatient(struct patient *patient);
void listPatients(struct patient *patients, int count);