/***********************************************************************
 * project1b.c
 * A program to store, compute and display coursework marks for a module
 * 215800
 * 29/10/19
 * ********************************************************************/

#include <stdio.h>
#define MAX_STUDENTS 75

void displayTitle(char title[]);
void clearScreen(void);
void clearBuffer(void);
void confirm(void);
int getNumber(char message[]);
void getStudentNames(struct student *, int count);
void getStudentMarks(struct student *, int count);
void confirmInputtedMarks(struct student *, int count);
void calculateStudentMark(struct student *);
void updateStudentMark(struct student *);
void updateStudentName(struct student *);
void addNewStudent(struct student *, int studentCount);
void displayStudent(struct student *, int studentId);

typedef struct student {
    int id;
    char name[30];
    int coursework1;
    int coursework2;
    int coursework3;
};


int main(void)
{
    /* Request candidate number */
    /* Request X names */
    /* Enter main loop running until exit condition is met */
    /* Show menu options */
    /* Use if statements to handle each of the three modes, break on 
    exit */

    /* OPTION 1 */
    /* Loop through each student and request coursework number */
    /* Request mark */
    /* Show entered data */
    /* Confirm entered data */
    /* Discard on refusal, save on confirmation */

    /* OPTION 2 */
    /* Request student number */
    /* Search for student */
    /* Calculate mark */

    /* OPTION 3 */
    /* Verify PIN */
    /* Show suboptions */
    /* OPTION A */
    /* Request and store new PIN */
    /* OPTION B */
    /* Request student number */
    /* Request which mark to change */
    /* Input and save new mark */
    /* OPTION C */
    /* Request student name */
    /* Request each mark */
    /* Display new student record */
    /* OPTION D */
    /* Request student number */
    /* Input and save new name */

    /* OPTION 4 */
    /* Break loop */

    return 0;
}

void displayTitle(void)
{
    /* Display title */
}

void clearScreen(void)
{
    /* Print a good chunk of lines to clear the screen */
}

void clearBuffer(void)
{
    /* Clear input buffer */
}

int getNumber(char message[])
{
    /* Gets and returns a whole number */
}

void getName(char message[], struct student *dest)
{
    /* Gets and stores a student name */
}

void getStudentNames(struct student *dest[])
{
    /* Gets all students names */
}

void getStudentMarks(struct student *dest[])
{
    /* Gets all students marks */
}

void confirmInputtedMarks(struct student *students[])
{
    /* Prints and confirms student marks */
}

void calculateStudentMarks(struct student *students[])
{
    /* Requests student number and calculates marks */
}

void updateStudentMark(struct student *students[])
{
    /* Requests student number and updates marks */
}

void updateStudentName(struct student *students[])
{
    /* Requests student number and updates name */
}

void addNewStudent(struct student *students[])
{
    /* Adds new student */
}
