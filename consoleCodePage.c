#include "consoleCodePage.h"

#ifdef _WIN32 //_WIN16 ||
#include <windows.h>
#endif

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

void consoleCodePage_utf7()
{
    consoleCodePage(65000);
}

void consoleCodePage_utf8()
{
    consoleCodePage(65001);
}