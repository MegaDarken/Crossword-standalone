
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHash.h"
#include "crossword.h"
#include "valRead.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg};

constexpr size_t WIDTH_ARG_SHORT = stringHash("-w");

int main(int argc, char** argv)
{
    const int defaultValue = 0;

    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;

    enum argsMode mode = noArg;

    for (size_t i = 0; i < argc; i++)
    {
        
        switch (stringHash_nullTerminated(argv[i]))
        {
        case WIDTH_ARG_SHORT:
            /* code */
            break;
        
        default:
            break;
        }
    }

    //User inputs
    if (width == defaultValue)
    {
        printf("\nEnter width:");
        valRead_intDest(&width, "\007\nInput must be an integer:");
    }

    if (height == defaultValue)
    {
        printf("\nEnter height:");
        valRead_intDest(&height, "\007\nInput must be an integer:");
    }

    if (wordCount == defaultValue)
    {
        printf("\nEnter wordCount:");
        valRead_size_tDest(&wordCount, "\007\nInput must be an integer:");
    }

    crossword(width, height, wordCount);

}
