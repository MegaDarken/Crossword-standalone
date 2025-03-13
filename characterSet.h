
#ifndef __CHARACTER_SET__
#define __CHARACTER_SET__

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef _WIN32 //_WIN16 ||
void winError_printLast();
#endif //_WIN16 || _WIN32

void characterSet_Reset();
void characterSet_UTF8();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__CHARACTER_SET__
