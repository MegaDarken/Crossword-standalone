#ifndef __PRINT_TIME__
#define __PRINT_TIME__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_ymd(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_ymd();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_dmy(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_dmy();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_mdy(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_mdy();

#endif // __PRINT_TIME__
