
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHash.h"
#include "crossword.h"
#include "valRead.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg};

const size_t WIDTH_ARG_SHORT = stringHash("-w");
const size_t WIDTH_ARG = stringHash("--width");
const size_t HEIGHT_ARG_SHORT = stringHash("-h");
const size_t HEIGHT_ARG = stringHash("--height");
const size_t WORDC_ARG_SHORT = stringHash("-c");
const size_t WORDC_ARG = stringHash("--count");


int main(int argc, char** argv)
{
    const int defaultValue = 0;

    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;

    enum argsMode mode = noArg;

    for (size_t i = 0; i < argc; i++)
    {
        switch (mode)
        {
        case noArg:
            switch (stringHash_nullTerminated(argv[i]))
            {
            case WIDTH_ARG_SHORT:
            case WIDTH_ARG:
                mode = widthArg;
                break;

            case HEIGHT_ARG_SHORT:
            case HEIGHT_ARG:
                mode = heightArg;
                break;

            case WORDC_ARG_SHORT:
            case WORDC_ARG:
                mode = wordCountArg;
                break;
            
            default:
                break;
            }
            break;
        
        case widthArg:
            if (1 == sscanf(argv[i], "%d", &width)) mode = noArg;
            break;

        case heightArg:
            if (1 == sscanf(argv[i], "%d", &height)) mode = noArg;
            break;

        case wordCountArg:
            if (1 == sscanf(argv[i], "%zu", &wordCount)) mode = noArg;
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
