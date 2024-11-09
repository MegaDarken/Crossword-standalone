//Ensure loaded only once
#ifndef __WRAW_READ__
#define __WRAW_READ__

#include <unistd.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
ssize_t wrawReadBuffer(void* array, ssize_t count);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int wrawRead();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wrawReadLoop(const int escape);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char wrawReadBool(const int trueChar, const int falseChar);

#endif //__WRAW_READ__
