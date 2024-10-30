
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stringHash.h"
#include "crossword.h"
#include "valRead.h"
#include "randomTable.h"
#include "fileUtility.h"
#include "printTime.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg, firstCharArg, listFilenameArg, outputFilenameArg, seedArg};

constexpr __UINT64_TYPE__ WIDTH_ARG_SHORT = stringHash("-w");
constexpr __UINT64_TYPE__ WIDTH_ARG = stringHash("--width");
constexpr __UINT64_TYPE__ HEIGHT_ARG_SHORT = stringHash("-h");
constexpr __UINT64_TYPE__ HEIGHT_ARG = stringHash("--height");
constexpr __UINT64_TYPE__ WORDC_ARG_SHORT = stringHash("-c");
constexpr __UINT64_TYPE__ WORDC_ARG = stringHash("--count");
constexpr __UINT64_TYPE__ FIRST_ARG_SHORT = stringHash("-f");
constexpr __UINT64_TYPE__ FIRST_ARG = stringHash("--first");
constexpr __UINT64_TYPE__ LIST_FILENAME_ARG_SHORT = stringHash("-l");
constexpr __UINT64_TYPE__ LIST_FILENAME_ARG = stringHash("--list");
constexpr __UINT64_TYPE__ OUTPUT_FILENAME_ARG_SHORT = stringHash("-o");
constexpr __UINT64_TYPE__ OUTPUT_FILENAME_ARG = stringHash("--output");
constexpr char RANDOM_ARG_SHORT = 'r';
constexpr __UINT64_TYPE__ RANDOM_ARG = stringHash("--random");
constexpr char DETERMINISTIC_ARG_SHORT = 'd';
constexpr __UINT64_TYPE__ DETERMINISTIC_ARG = stringHash("--deterministic");
constexpr __UINT64_TYPE__ SEED_ARG_SHORT = stringHash("-s");
constexpr __UINT64_TYPE__ SEED_ARG = stringHash("--seed");

int main(int argc, char** argv)
{
    const int defaultValue = 0;

    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;
    int startingChar = defaultValue;
    char* listFileName = (char*)"wordQuestions.txt";
    char* outputFileName = NULL;
    int randomBool = 0;
    int deterministicBool = 0;
    __UINT64_TYPE__ seed = 0;

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

        case OUTPUT_FILENAME_ARG_SHORT:
        case OUTPUT_FILENAME_ARG:
            mode = outputFilenameArg;
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
                mode = noArg;
                break;

            case outputFilenameArg:
                outputFileName = argv[i];
                mode = noArg;
                break;

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
        printf("\nEnter starting character:");
        valRead_wcharDest(&startingChar, "\007\nInput must be an character:");
    }

    if (deterministicBool) randomTable_indicesFromTable();

    FILE *outputStream = stdout;

    if (outputFileName != NULL)
    {
        outputStream = fileUtility_open(outputFileName, "a");
    }

    fprintTime_ymd(outputStream);
    fprintf(outputStream, "\n");
    crossword(outputStream, width, height, wordCount, startingChar, listFileName, randomBool, seed);

    if (outputFileName != NULL)
    {
        fclose(outputStream);
    }
}
