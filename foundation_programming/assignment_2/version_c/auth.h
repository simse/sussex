/***********************************************************************
 * auth.h
 * Auth function prototypes
 * Simon Sorensen
 * 21/11/19
 * Version c
 * ********************************************************************/

#include "nurse.h"

#pragma once

void loadAuth(struct nurse nurses[]);
void saveAuth(struct nurse nurses[]);
void consultantLogin(void);
_Bool verifyFormat(char input[]);
_Bool verifyLine(char c);
int countNurses(void);
void listNurses(void);
int selectNurse(char* message);
void editNurses(void);
void addNurse(void);
void deleteNurse(void);