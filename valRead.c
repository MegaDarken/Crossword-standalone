#include "valRead.h"

#include <stdio.h>

#define VALREAD_BUFFERSIZE 256

void valRead_charDest(char *dest, char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            while (getchar() != '\n');
        }
    }
}

char valRead_char(char *invalidInputText)
{
    char output;
    valRead_charDest(&output, invalidInputText); 
    return output;
}

void valRead_wcharDest(int *dest, char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            while (getchar() != '\n');
        }
    }
}

char valRead_wchar(int *invalidInputText)
{
    char output;
    valRead_charDest(&output, invalidInputText); 
    return output;
}

void valRead_intDest(int *dest, char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %d", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            while (getchar() != '\n');
        }
    }
}

int valRead_int(char *invalidInputText)
{
    int output;
    valRead_intDest(&output, invalidInputText); 
    return output;
}

void valRead_size_tDest(size_t *dest, char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %zu", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            while (getchar() != '\n');
        }
    }
}

size_t valRead_size_t(char *invalidInputText)
{
    int output;
    valRead_intDest(&output, invalidInputText); 
    return output;
}