#include "consoleProcessing.h"

#ifdef _WIN32 //_WIN16 ||
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void enableConsoleProcessing()
{
#ifdef _WIN32 //_WIN16 ||
    HANDLE consoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO initialConsoleAttributes;
    
    GetConsoleScreenBufferInfo(consoleOutputHandle, &initialConsoleAttributes);

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
