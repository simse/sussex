/***********************************************************************
 * encrypt.c
 * Functions for encryption module
 * Simon Sorensen
 * 21/11/19
 * ********************************************************************/

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "encrypt.h"

char* encrypt(char input[], int length)
{
    char *tmp;
    tmp = (char *) malloc(length);
    strcpy(tmp, input);
    for(int i = 0; i < length; i++)
    {
        char current_char = tmp[i];
        /* numbers */
        if(current_char > 47 && current_char < 58)
        {
            tmp[i] = (current_char + 8 > 57) ? 
                current_char - 2 : 
                current_char + 8;
        }
        /* lowercase letters */
        else if(current_char > 64 && current_char < 91) 
        {
            tmp[i] = (current_char + 8 > 90) ? 
                current_char - 18 : 
                current_char + 8;
        }
        /* uppercase letters */
        else if(current_char > 96 && current_char < 123)
        {
            tmp[i] = (current_char + 8 > 122) ? 
                current_char - 18 : 
                current_char + 8;
        }
    }
    return tmp;
}

char* decrypt(char input[], int length)
{
    char *tmp;
    tmp = (char *) malloc(length);
    strcpy(tmp, input);
    for(int i = 0; i < length; i++)
    {
        char current_char = tmp[i];
        /* numbers */
        if(current_char > 47 && current_char < 58)
        {
            tmp[i] = (current_char - 8 < 48) ? 
                current_char + 2 : 
                current_char - 8;
        }
        /* lowercase letters */
        else if(current_char > 64 && current_char < 91) 
        {
            tmp[i] = (current_char - 8 < 65) ? 
                current_char + 18 : 
                current_char - 8;
        }
        /* uppercase letters */
        else if(current_char > 96 && current_char < 123)
        {
            tmp[i] = (current_char - 8 < 97) ? 
                current_char + 18 : 
                current_char - 8;
        }
    }
    return tmp;
}

char* encryptNum(int num)
{
    int length = (int)(num ? log10(num) + 1 : 1);
    char *tmp;
    tmp = (char *) malloc(length);
    sprintf(tmp, "%d", num);
    return encrypt(tmp, 8);
}

int decryptNum(char* num)
{
    return atoi(decrypt(num, 8));
}