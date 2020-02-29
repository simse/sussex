/***********************************************************************
 * auth.c
 * Auth constants and function declarations
 * Simon Sorensen
 * 21/11/19
 * Version c
 * ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "auth.h"
#include "encrypt.h"

void loadAuth(struct nurse nurses[])
{
    FILE *auth;
    char tmp[BUFFER_SIZE];
    auth = fopen("auth.txt", "r");
    _Bool stop = 0;
    for (int nurse = 0; nurse < MAX_NURSES; nurse++)
    {
        if (stop)
            break;
        for (int field = 0; field < 3; field++)
        {
            fgets(tmp, BUFFER_SIZE, (FILE *)auth);
            if (feof(auth))
            {
                stop = 1;
                break;
            }
            strtok(tmp, "\n");
            strcpy(tmp, decrypt(tmp, BUFFER_SIZE));
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

void consultantLogin(void)
{
    FILE *auth;
    auth = fopen("login.txt", "r");
    char username[9], password[9];
    char null[BUFFER_SIZE];
    fgets(username, 9, (FILE *)auth);
    fgets(password, 9, (FILE *)auth);
    fgets(password, 9, (FILE *)auth);
    fclose(auth);
    /* Decrypt */
    strtok(username, "\n");
    strtok(password, "\n");
    strcpy(username, decrypt(username, 9));
    strcpy(password, decrypt(password, 9));
    char iUsername[9], iPassword[9];
    do {
        printf("Username: ");
        scanf("%[^\n]", iUsername);
        getchar();
        printf("Password: ");
        scanf("%[^\n]", iPassword);
        getchar();
        puts("\n");
    } while(strcmp(username, iUsername) && strcmp(password, iPassword));
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

_Bool verifyLine(char c)
{
    if (c > 47 && c < 58)
    {
        return 1;
    }

    if (c > 64 && c < 91)
    {
        return 1;
    }

    if (c > 97 && c < 123)
    {
        return 1;
    }

    return 0;
}

int countNurses(void)
{
    struct nurse nurses[MAX_NURSES];
    int count = 0;
    loadAuth(nurses);
    for (int i = 0; i < MAX_NURSES; i++)
    {
        if (verifyLine(nurses[i].name[0]))
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

void listNurses(void)
{
    struct nurse nurses[MAX_NURSES];
    loadAuth(nurses);
    puts("The nurses are:");
    for (int i = 0; i < countNurses(); i++)
    {
        printf("- %d: %s\n", i + 1, nurses[i].name);
    }
}

int selectNurse(char *message)
{
    int nurse;
    listNurses();
    do
    {
        printf("\n%s ", message);
        scanf("%d%*c", &nurse);
    } while (nurse < 0 && nurse > MAX_NURSES);
    return nurse;
}

void editNurses(void)
{
    int nurse = selectNurse("Which nurse would you like to edit?");
    struct nurse nurses[MAX_NURSES];
    loadAuth(nurses);
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
    strcpy(nurses[nurse - 1].id, username);
    strcpy(nurses[nurse - 1].password, password);
    saveAuth(nurses);
    printf("\n\nCredentials saved!");
}

void addNurse(void)
{
    struct nurse nurses[MAX_NURSES];
    int currentNurseCount = countNurses();
    loadAuth(nurses);
    char name[255], username[9], password[9];
    printf("\nEnter nurse name: ");
    scanf("%[^\n]", name);
    getchar();
    do
    {
        printf("\nNurse username: ");
        scanf("%[^\n]", &username);
        getchar();
    } while (!verifyFormat(username));
    do
    {
        printf("\nNurse password: ");
        scanf("%[^\n]", &password);
        getchar();
    } while (!verifyFormat(password));
    /* Move to nurse struct */
    strcpy(nurses[currentNurseCount].name, name);
    strcpy(nurses[currentNurseCount].id, username);
    strcpy(nurses[currentNurseCount].password, password);
    saveAuth(nurses);
    puts(GREEN "Nurse added!" RESET);
}

void deleteNurse(void)
{
    int nurse = selectNurse("Which nurse would you like to delete?") - 1;
    int nurseCount = countNurses();
    struct nurse nurses[MAX_NURSES];
    loadAuth(nurses);
    /* Shift every element back starting at position X */
    for (int i = nurse; i + 1 < nurseCount; i++)
    {
        strcpy(nurses[nurse].name, nurses[nurse + 1].name);
        strcpy(nurses[nurse].id, nurses[nurse + 1].id);
        strcpy(nurses[nurse].password, nurses[nurse + 1].password);
    }
    /* Delete last element */
    strcpy(nurses[nurseCount - 1].name, "");
    strcpy(nurses[nurseCount - 1].id, "");
    strcpy(nurses[nurseCount - 1].password, "");
    saveAuth(nurses);
    puts(GREEN "Nurse deleted!" RESET);
}

void saveAuth(struct nurse nurses[])
{
    FILE *auth;
    auth = fopen("auth.txt", "w");
    for (int nurse = 0; nurse < MAX_NURSES; nurse++)
    {
        if (!verifyLine(nurses[nurse].name[0]))
            break;
        fprintf(auth, "%s\n%s\n%s\n",
                encrypt(nurses[nurse].name, strlen(nurses[nurse].name) + 1),
                encrypt(nurses[nurse].id, strlen(nurses[nurse].id) + 1),
                encrypt(nurses[nurse].password, strlen(nurses[nurse].password) + 1));
    }
    fclose(auth);
}