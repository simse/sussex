/*******************************************************************************
 * display_design.c
 * 
 * 215800
 * 29/10/19
 * ****************************************************************************/

#include <stdio.h>

int main(void)
{
    puts("| ================================================== |");
    printf("| %-50s |\n", "University of Sussex module manager");
    printf("| %-50s |\n", "Module name: Foundation Programming");
    printf("| %-50s |\n", "Module code: G6065");
    printf("| %-50s |\n", "Module convenor: Richard A Handy");
    puts("| ================================================== |\n\n\n");

    printf("Please enter number of students: 4\n\n");

    puts("| -- | ---------------------------- |");
    puts("|  1 | Enter student name: ");
    puts("|  2 | Enter student name: ");
    puts("|  3 | Enter student name: ");
    puts("|  4 | Enter student name: ");
    puts("| -- | ---------------------------- |\n");
    puts("Student info saved successfully!\n\n\n");

    puts("1. Enter marks");
    puts("2. Display student mark");
    puts("3. Supervisor mode");
    puts("4. Exit\n");
    puts("Please select and option: 1\n\n");

    puts("Stephen");
    puts("=======");
    puts("Please enter mark for coursework 1: ");
    puts("Please enter mark for coursework 2: ");
    puts("Please enter mark for coursework 3: ");
    puts("\nSaved!\n\n");


    return 0;
}