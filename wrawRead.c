//Source: https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
#include "wrawRead.h"

#include "rawRead.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
ssize_t wrawReadBuffer(void* array, ssize_t count)
{
    enableRawMode();

    ssize_t result;
#ifdef _WIN32 //_WIN16 ||
    ((int*)array)[0] = getchar();
    result = 1;
#else //_WIN16 || _WIN32
    result = read(STDIN_FILENO, array, count);
    if ( result != 1 )
    {
        wprintf(L"Issue with rawRead: ");

        if (iscntrl(((int*)array)[0]))
        {
            wprintf(L"%s\n", ((char*)array));
        }
        else
        {
            wprintf(L"%d ('%s')\n", ((int*)array)[0], ((char*)array));
        }
    }
#endif //_WIN16 || _WIN32

    disableRawMode();

    return result;
} 

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int wrawRead()
{
  int c = 0;
  wrawReadBuffer(&c, 2);

  return c;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wrawReadLoop(const int escape)
{
    enableRawMode();

    int c = 0;

#ifdef _WIN32 //_WIN16 ||
    for (c = getchar();c != escape;c = getchar())
#else //_WIN16 || _WIN32
    while (read(STDIN_FILENO, &c, 2) == 1 && c != escape)
#endif //_WIN16 || _WIN32
    {
        if (iscntrl(c))
        {
            wprintf(L"%s\n", ((char*)&c));
        }
        else
        {
            wprintf(L"%d ('%s')\n", c, ((char*)&c));
        }
    }

    disableRawMode();
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char wrawReadBool(const int trueChar, const int falseChar)
{
    for (;;)
    {
        wprintf(L"(%c/%c):\n", trueChar, falseChar);
        int input = rawRead();
        if (input == trueChar) return 1;
        if (input == falseChar) return 0;
    }
}
