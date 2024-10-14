
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringHash.h"
#include "crossword.h"
#include "valRead.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg, firstCharArg};

constexpr size_t WIDTH_ARG_SHORT = stringHash("-w");
constexpr size_t WIDTH_ARG = stringHash("--width");
constexpr size_t HEIGHT_ARG_SHORT = stringHash("-h");
constexpr size_t HEIGHT_ARG = stringHash("--height");
constexpr size_t WORDC_ARG_SHORT = stringHash("-c");
constexpr size_t WORDC_ARG = stringHash("--count");
constexpr size_t FIRST_ARG_SHORT = stringHash("-f");
constexpr size_t FIRST_ARG = stringHash("--first");

int main(int argc, char** argv)
{
    const int defaultValue = 0;

    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;
    int startingChar = defaultValue;

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
            
            case FIRST_ARG_SHORT:
            case FIRST_ARG:
                mode = firstCharArg;
                break;
            
            default:
                break;
            }
            break;
        
        case widthArg:
            if (1 == sscanf(argv[i], " %d", &width)) mode = noArg;
            break;

        case heightArg:
            if (1 == sscanf(argv[i], " %d", &height)) mode = noArg;
            break;

        case wordCountArg:
            if (1 == sscanf(argv[i], " %zu", &wordCount)) mode = noArg;
            break;

        case firstCharArg:
            startingChar = argv[i][0];
            mode = noArg;
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

    if (startingChar == defaultValue)
    {
        printf("\nEnter stating character:");
        valRead_wcharDest(&startingChar, "\007\nInput must be an character:");
    }

    crossword(width, height, wordCount, startingChar);

}
