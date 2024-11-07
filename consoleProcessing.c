#include "consoleProcessing.h"

#ifdef _WIN32 //_WIN16 ||
#include <windows.h>

HANDLE consoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
int initalConsoleAttributes = GetConsoleScreenBufferInfo(consoleOutputHandle);
char ansiColor_initSuccess = 0;
#endif

void enableConsoleProcessing()
{
#ifdef _WIN32 //_WIN16 ||
    DWORD dwordMode;

    GetConsoleMode(consoleOutputHandle, &dwordMode);
    
    dwordMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(consoleOutputHandle, dwordMode))
    {
        perror("SetConsoleMode failed. Expect ");
        return;
    }
#endif
}
