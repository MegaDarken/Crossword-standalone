#include "wvalRead.h"

#include <stdio.h>
#include <wchar.h>

#include "clearInput.h"

#define VALREAD_BUFFERSIZE 256

void wvalRead_charDest(char *dest, const wchar_t *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", dest);

        if (result == 1) return;
        else
        {
            wprintf(L"%ls", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

char wvalRead_char(const wchar_t *invalidInputText)
{
    char output;
    wvalRead_charDest(&output, invalidInputText); 
    return output;
}

void wvalRead_wcharDest(int *dest, const wchar_t *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", (char*)dest);

        if (result == 1) return;
        else
        {
            wprintf(L"%ls", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

int wvalRead_wchar(const wchar_t *invalidInputText)
{
    int output;
    wvalRead_wcharDest(&output, invalidInputText); 
    return output;
}

void wvalRead_intDest(int *dest, const wchar_t *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %d", dest);

        if (result == 1) return;
        else
        {
            wprintf(L"%ls", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

int wvalRead_int(const wchar_t *invalidInputText)
{
    int output;
    wvalRead_intDest(&output, invalidInputText); 
    return output;
}

void wvalRead_size_tDest(size_t *dest, const wchar_t *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %zu", dest);

        if (result == 1) return;
        else
        {
            wprintf(L"%ls", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

size_t wvalRead_size_t(const wchar_t *invalidInputText)
{
    int output;
    wvalRead_intDest(&output, invalidInputText); 
    return output;
}