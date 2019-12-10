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
char* enterPassword(void);