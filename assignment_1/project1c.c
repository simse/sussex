/***********************************************************************
 * project1c.c
 * A program to store, compute and display coursework marks for a module
 * 215800
 * 29/10/19
 * ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 75
#define MAX_NAME_LENGTH 100

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    int marks[3];
};

void displayTitle(char title[]);
void displayOptions(void);
void clearScreen(void);
void clearBuffer(void);
void confirm(void);
int getNumber(char message[]);
int getStudentCount(void);
int getMark(char message[]);
int getStudentId(char message[], int studentCount);
int getOption(void);
void getStudentNames(struct student students[], int studentCount);
void getStudentMarks(struct student students[],
    int studentCount,
    int coursework);
void getCourseworkMarks(struct student students[], int studentCount);
void confirmInputtedMarks(struct student students[], int studentCount);
void calculateStudentMark(struct student students[], int studentCount);
void updateStudentMark(struct student students[],
    int studentCount);
void updateStudentName(struct student students[], int studentCount);
void addNewStudent(struct student students[], int studentCount);
void displayStudent(struct student students[], int studentId);
void displayAllStudents(struct student students[], int studentCount);
void supervisorMode(struct student students[], int studentCount, int pin);


int main(void)
{
    displayTitle("");
    int studentCount = getNumber("How many students are there in your" \
        " class? ");
    while(studentCount > MAX_STUDENTS)
    {
        printf("You can have no more than 75 students in a class!\n\n");
        studentCount = getNumber("How many students are there in your" \
        " class? ");
    }

    struct student students[MAX_STUDENTS];
    int hasInputtedMarks[] = {0, 0, 0};

    getStudentNames(students, studentCount);
    confirm();

    int option;
    int pin = 4444;
    while(option != 4)
    {
        clearScreen();
        displayTitle("University of Sussex module manager");
        puts("1. Enter marks");
        puts("2. Display student mark");
        puts("3. Supervisor mode");
        puts("4. Exit\n");
        printf("Please select and option: ");
        scanf("%d", &option);

        if(option == 1)
        {
            int coursework = getNumber("Which coursework mark would " 
                "you like to enter? ");
            while(coursework > 3 || coursework < 1)
            {
                printf("\n\nPlease select coursework 1, 2 or 3.\n\n");
                coursework = getNumber("Which coursework mark would " 
                    "you like to enter? ");
            }
            if(hasInputtedMarks[coursework - 1]) {
                puts("\nYou've already entered marks for that " 
                    "coursework! To change marks, enter supervisor " 
                    "mode.");
                confirm();
            } else {
                getStudentMarks(students, studentCount, coursework);
                confirmInputtedMarks(students, studentCount);
                hasInputtedMarks[coursework - 1] = 1;
            }
        }

        if(option == 2)
        {
            calculateStudentMark(students, studentCount);
        }

        if(option == 3)
        {
            supervisorMode(students, studentCount, pin);
        }

        if(option == 4)
        {
            puts("\n\nGoodbye y'all!\n");
            confirm();
        }
    }

    return 0;
}

/* Will format and display inputted title or default */
void displayTitle(char title[])
{
    if(title == "")
    {
        puts("| ================================================== |");
        printf("| %-50s |\n", "University of Sussex module manager");
        printf("| %-50s |\n", "Module name: Foundation Programming");
        printf("| %-50s |\n", "Module code: G6065");
        printf("| %-50s |\n", "Module convenor: Richard A Handy");
        puts("| ================================================== |");
        printf("\n\n");
    } else {
        puts("| ================================================== |");
        printf("| %-50s |\n", title);
        puts("| ================================================== |");
        printf("\n\n");
    }
}

/* Will clear screen using a system call */
void clearScreen(void)
{
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
}

/* Flushes input buffer */
void clearBuffer(void)
{
    fflush(stdin);
}

/* Pauses screen until any key is pressed */
void confirm(void)
{
    clearBuffer();
    printf("Press any key to continue...");
    getchar();
}

/* Gets number from screen after printing message */
int getNumber(char message[])
{
    int number;
    printf(message);
    scanf("%d", &number);
    clearBuffer();
    return number;
}

/* Gets number but applies input constraint; 0 =< mark =< 100 */
int getMark(char message[])
{
    int minimum = 0;
    int maximum = 100;
    int number = getNumber(message);
    while(number > maximum || number < minimum)
    {
        printf("\nWoops! Please type a number between %d and %d.\n\n",
            minimum,
            maximum);
        number = getNumber(message);
    }
    return number;
}

/* Gets student ID and makes sure student ID exists */
int getStudentId(char message[], int studentCount)
{
    int number = getNumber(message);
    while(number > studentCount || number < 1)
    {
        printf("\nWoops! That's not a valid student ID. The highest "
            "ID is %d.\n\n", studentCount);
        number = getNumber(message);
    }
    return number - 1; /* Return as array index */
}

/* Will ask for student names given count */
void getStudentNames(struct student students[], int studentCount)
{
    printf("\n| -- | ---------------------------- |\n");
    for(int i = 0; i <= studentCount - 1; i++)
    {
        char name[MAX_NAME_LENGTH];
        printf("| %2d | Enter student name: ", i + 1);
        scanf("%s", name);
        strcpy(students[i].name, name);
    }
    printf("| -- | ---------------------------- |");
    puts("\n\nStudent names saved successfully!\n");
}

/* Will get coursework marks given student count and coursework */
void getStudentMarks(struct student students[], int studentCount,
    int coursework)
{
    clearScreen();
    clearBuffer();
    char title[255];
    sprintf(&title, "Editing marks for coursework %d", coursework);
    displayTitle(title);

    for(int i = 0; i <= studentCount - 1; i++)
    {
        clearBuffer();
        printf("%s: ", students[i].name, coursework);
        students[i].marks[coursework - 1] = getMark("");
        printf("\n");
    }
}

/* Displays student marks and allow editing until confirmation */
void confirmInputtedMarks(struct student students[], int studentCount)
{
    _Bool firstLoop = 1;
    char confirm;
    while(confirm != 'y' || confirm == 'Y')
    {
        if(firstLoop)
        {
            firstLoop = 0;
        } else
        {
            updateStudentMark(students, studentCount);
        }
        while(confirm != 'n' && confirm != 'N' &&
            confirm != 'y' && confirm != 'Y')
        {
            displayAllStudents(students, studentCount);
            printf("\nIs the above correct? (y/n) ");
            clearBuffer();
            scanf("%c", &confirm);
            clearBuffer();
        }
    }
}

/* Will compute a final mark for a student */
void calculateStudentMark(struct student students[], int studentCount)
{
    displayAllStudents(students, studentCount);
    int studentId = getStudentId(
        "\n\n\nWhich student would you like to see? (enter ID): ",
        studentCount);
    float mark = students[studentId].marks[0] * 0.2 +
                 students[studentId].marks[1] * 0.3 +
                 students[studentId].marks[2] * 0.5;
    clearScreen();
    displayTitle("Student information");
    displayStudent(students, studentId);
    printf("Final grade: %.1f%% / 100.0%%\n\n\n", mark);
    confirm();
}

/* Allows updating a single mark for a single student */
void updateStudentMark(struct student students[], int studentCount)
{
    displayAllStudents(students, studentCount);
    printf("\n\n\n");
    int studentId = getStudentId(
        "Which student would you like to edit? (enter ID): ",
        studentCount);
    int coursework = getNumber("\nWhich coursework would you like to "
        "update?");
    printf("\n\nPlease enter a mark for coursework %d: ", coursework);
    students[studentId].marks[coursework - 1] = getMark("");
    printf("\n\nMark updated!");
    confirm();
}

/* Allows updating a student name given ID */
void updateStudentName(struct student students[], int studentCount)
{
    clearScreen();
    displayTitle("Editing student");
    displayAllStudents(students, studentCount);
    printf("\n\n\n");
    int studentId = getStudentId(
        "Which student would you like to edit? (enter ID): ",
        studentCount);
    char name[MAX_NAME_LENGTH];
    printf("Enter updated student name: ");
    scanf("%s", name);
    strcpy(students[studentId].name, name);
    printf("\n\nStudent name updated!\n\n");
    confirm();
}

/* Will add a new student */
void addNewStudent(struct student students[], int studentCount)
{
    clearScreen();
    displayTitle("Add new student");
    char name[MAX_NAME_LENGTH];
    printf("\n\nEnter student name: ");
    scanf("%s", name);
    strcpy(students[studentCount].name, name);
    puts("\nNew student added!\n\n");
    confirm();
}

/* Will display student record */
void displayStudent(struct student students[], int studentId)
{
    int nameLength = strlen(students[studentId].name);
    printf("==========================================\n");
    printf("| ID | %-*s | C1  | C2  | C3  |\n", nameLength, "name");
    printf(
        "| %2d | %-*s | %-3d | %-3d | %-3d |\n",
        studentId + 1,
        nameLength,
        students[studentId].name,
        students[studentId].marks[0],
        students[studentId].marks[1],
        students[studentId].marks[2]
    );
    printf("==========================================\n\n");
}

/* Will display all students in a table */
void displayAllStudents(struct student students[], int studentCount)
{
    printf("| ID | Name            | C1  | C2  | C3  |\n");
    for(int i = 0; i <= studentCount - 1; i++)
    {
        printf(
            "| %2d | %-15s | %-3d | %-3d | %-3d |\n",
            i+1,
            students[i].name,
            students[i].marks[0],
            students[i].marks[1],
            students[i].marks[2]
        );
    }
}

/**/
void supervisorMode(struct student students[], int studentCount, int pin)
{
    /* Verify PIN */
            while(getNumber("\nPlease enter the PIN code: ") != pin)
            {
                printf("\n\nWrong PIN!\n");
            }
            char suboption = 0;
            while(suboption != 'e' && suboption != 'E')
            {
                clearScreen();
                displayTitle("Supervisor mode");
                puts("In supervisor mode you can add and edit " 
                    "student information.\n");
                puts("a. Change PIN");
                puts("b. Change student mark");
                puts("c. Add new student");
                puts("d. Edit student name");
                puts("e. Exit supervisor mode\n");
                printf("Please select an option: ");
                scanf("%c", &suboption);

                if(suboption == 'a' || suboption == 'A')
                {
                    pin = getNumber("\n\nPlease enter new PIN: ");
                    puts("\nPIN updated!\n\n");
                    confirm();
                }

                if(suboption == 'b' || suboption == 'B')
                {
                    updateStudentMark(students, studentCount);
                }

                if(suboption == 'c' || suboption == 'C')
                {
                    if(studentCount >= MAX_STUDENTS)
                    {
                        printf("\n\nSorry, maximum students reached. "
                            "You can have no more than 75 students "
                            "at once.");
                        confirm();
                    } else
                    {
                        addNewStudent(students, studentCount++);
                    }
                    
                }

                if(suboption == 'd' || suboption == 'D')
                {
                    clearScreen();
                    displayTitle("Editing student");

                    updateStudentName(students, studentCount);
                }

                if(suboption == 'e' || suboption == 'E')
                {
                    continue;
                }
            }
}