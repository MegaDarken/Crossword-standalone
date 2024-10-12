#ifndef __VAL_READ__
#define __VAL_READ__

#include "stdlib.h"

void valRead_charDest(char *dest, char *invalidInputText);
char valRead_char(char *invalidInputText);

void valRead_intDest(int *dest, char *invalidInputText);
int valRead_int(char *invalidInputText);

void valRead_size_tDest(size_t *dest, char *invalidInputText);
size_t valRead_size_t(char *invalidInputText);

#endif //__VAL_READ__