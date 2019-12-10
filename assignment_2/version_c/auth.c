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

#include "auth.h"
#include "encrypt.h"

#define FILE_BUFFER 55

void loadAuth(struct nurse nurses[])
{
    FILE *auth;
    char tmp[FILE_BUFFER];
    auth = fopen("auth.txt", "r");
    _Bool stop = 0;
    for (int nurse = 0; nurse < 10; nurse++)
    {
        if (stop) break;
        for (int field = 0; field < 3; field++)
        {
            fgets(tmp, FILE_BUFFER, (FILE *)auth);
            if(feof(auth))
            {
                stop = 1;
                break;
            }
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

_Bool verifyLine(char c)
{
    if(c > 47 && c < 58)
    {
        return 1;
    }

    if(c > 64 && c < 91)
    {
        return 1;
    }

    if(c > 97 && c < 123)
    {
        return 1;
    }

    return 0;
}

void saveAuth(struct nurse nurses[])
{
    FILE *auth;
    auth = fopen("auth.txt", "w");
    for (int nurse = 0; nurse < 10; nurse++)
    {
        //printf("%d", nurses[nurse].name[0]);
        if(!verifyLine(nurses[nurse].name[0])) break;
        fprintf(auth, "%s\n%s\n%s\n",
            encrypt(nurses[nurse].name, strlen(nurses[nurse].name) + 1),
            encrypt(nurses[nurse].id, strlen(nurses[nurse].id) + 1),
            encrypt(nurses[nurse].password, strlen(nurses[nurse].password) + 1));
    }
    fclose(auth);
}

char* enterPassword(void)
{
    return "";
}