//Ensure loaded only once
#ifndef __RAW_READ__
#define __RAW_READ__

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
long rawReadBuffer(char* array, long count);

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
