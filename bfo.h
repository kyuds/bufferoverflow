#ifndef BUFFER_OVERFLOW_TEST
#define BUFFER_OVERFLOW_TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable(char * input);

void not_called();

int is64bit();

#endif
