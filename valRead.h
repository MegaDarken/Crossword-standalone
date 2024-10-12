#ifndef __VAL_READ__
#define __VAL_READ__

#include "stdlib.h"

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
void valRead_charDest(char *dest, char *invalidInputText);

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
char valRead_char(char *invalidInputText);

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
void valRead_intDest(int *dest, char *invalidInputText);

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
int valRead_int(char *invalidInputText);

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
void valRead_size_tDest(size_t *dest, char *invalidInputText);

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
size_t valRead_size_t(char *invalidInputText);

#endif //__VAL_READ__