#ifndef __WVAL_READ__
#define __WVAL_READ__

#include "stdlib.h"

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wvalRead_charDest(char *dest, const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char wvalRead_char(const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wvalRead_wcharDest(int *dest, const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int wvalRead_wchar(const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wvalRead_intDest(int *dest, const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int wvalRead_int(const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wvalRead_size_tDest(size_t *dest, const wchar_t *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t wvalRead_size_t(const wchar_t *invalidInputText);

#endif //__WVAL_READ__