#ifndef __WPRINT_TIME__
#define __WPRINT_TIME__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_ymd(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_ymd();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_dmy(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_dmy();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_mdy(FILE *stream);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_mdy();

#endif // __WPRINT_TIME__
