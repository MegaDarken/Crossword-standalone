//Ensure loaded only once
#ifndef __RAW_READ__
#define __RAW_READ__

#include <unistd.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void disableRawMode();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void enableRawMode();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
ssize_t rawReadBuffer(void* array, ssize_t count);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char rawRead();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void rawReadLoop(char escape);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char rawReadBool(char trueChar, char falseChar);

#endif //__RAW_READ__
