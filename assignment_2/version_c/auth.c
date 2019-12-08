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

void saveAuth(struct nurse nurses[])
{
    FILE *auth;
    auth = fopen("auth.txt", "w");
    for (int nurse = 0; nurse < 5; nurse++)
    {
        fprintf(auth, "%s\n%s\n%s\n",
            encrypt(nurses[nurse].name, strlen(nurses[nurse].name) + 1),
            encrypt(nurses[nurse].id, strlen(nurses[nurse].id) + 1),
            encrypt(nurses[nurse].password, strlen(nurses[nurse].password) + 1));
    }
    fclose(auth);
}