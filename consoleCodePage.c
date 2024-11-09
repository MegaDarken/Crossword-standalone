#include "consoleCodePage.h"

#include <stdio.h>
#include <errno.h>

#ifdef _WIN32 //_WIN16 ||
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void consoleCodePage(unsigned int id)
{
#ifdef _WIN32 //_WIN16 ||
    if(IsValidCodePage(id))
    {
        SetConsoleCP(id);
    }
    else
    {
        perror("Error: Invalid code page.");
    }
#endif
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void consoleCodePage_utf7()
{
    consoleCodePage(65000);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void consoleCodePage_utf8()
{
    consoleCodePage(65001);
}