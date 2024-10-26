
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stringHash.h"
#include "crossword.h"
#include "valRead.h"
#include "randomTable.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg, firstCharArg, listFilenameArg, seedArg};

constexpr __uint64_t WIDTH_ARG_SHORT = stringHash("-w");
constexpr __uint64_t WIDTH_ARG = stringHash("--width");
constexpr __uint64_t HEIGHT_ARG_SHORT = stringHash("-h");
constexpr __uint64_t HEIGHT_ARG = stringHash("--height");
constexpr __uint64_t WORDC_ARG_SHORT = stringHash("-c");
constexpr __uint64_t WORDC_ARG = stringHash("--count");
constexpr __uint64_t FIRST_ARG_SHORT = stringHash("-f");
constexpr __uint64_t FIRST_ARG = stringHash("--first");
constexpr __uint64_t LIST_FILENAME_ARG_SHORT = stringHash("-l");
constexpr __uint64_t LIST_FILENAME_ARG = stringHash("--list");
constexpr char RANDOM_ARG_SHORT = 'r';
constexpr __uint64_t RANDOM_ARG = stringHash("--random");
constexpr char DETERMINISTIC_ARG_SHORT = 'd';
constexpr __uint64_t DETERMINISTIC_ARG = stringHash("--deterministic");
constexpr __uint64_t SEED_ARG_SHORT = stringHash("-s");
constexpr __uint64_t SEED_ARG = stringHash("--seed");

int main(int argc, char** argv)
{
    const int defaultValue = 0;

    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;
    int startingChar = defaultValue;
    char* listFileName = (char*)"wordQuestions.txt";
    int randomBool = 0;
    int deterministicBool = 0;
    __uint64_t seed = 0;

    enum argsMode mode = noArg;

    for (size_t i = 0; i < argc; i++)
    {
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

        case LIST_FILENAME_ARG_SHORT:
        case LIST_FILENAME_ARG:
            mode = listFilenameArg;
            break;

        case SEED_ARG_SHORT:
        case SEED_ARG:
            mode = seedArg;
            break;

        case RANDOM_ARG:
            randomBool = 1;
            break;

        case DETERMINISTIC_ARG:
            deterministicBool = 1;
            break;
        
        default:
            switch (mode)
            {
            case noArg:
                if (argv[i][0] == '-' && argv[i][1] != '-')
                {
                    for (size_t j = 0; argv[i][j]; j++)
                    {
                        switch (argv[i][j])
                        {
                        case RANDOM_ARG_SHORT:
                            randomBool = 1;
                            break;

                        case DETERMINISTIC_ARG_SHORT:
                            deterministicBool = 1;
                            break;
                        
                        default:
                            break;
                        }
                    }
                    
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

            case listFilenameArg:
                listFileName = argv[i];

            case seedArg:
                seed = stringHash(argv[i]);
                break;
            
            default:
                break;
            }
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

    if (deterministicBool) randomTable_indicesFromTable();

    crossword(width, height, wordCount, startingChar, listFileName, randomBool, seed);

}
