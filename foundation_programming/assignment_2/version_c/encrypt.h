/***********************************************************************
 * encrypt.h
 * Function declarations for encryption module
 * Simon Sorensen
 * 21/11/19
 * ********************************************************************/

#pragma once

char* encrypt(char input[], int length);
char* decrypt(char input[], int length);
char* encryptNum(int num);
int decryptNum(char* num);