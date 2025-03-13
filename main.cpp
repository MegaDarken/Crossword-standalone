
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#include "stringConstexpr.h"
#include "stringHash.h"
#include "consoleProcessing.h"
#include "consoleCodePage.h"
#include "crossword.h"
#include "clearInput.h"
#include "valRead.h"
#include "rawRead.h"
#include "randomTable.h"
#include "fileUtility.h"
#include "printTime.h"
#include "characterSet.h"

enum argsMode {noArg, widthArg, heightArg, wordCountArg, firstCharArg, iterationsArg, listFilenameArg, outputFilenameArg, seedArg, targetArg};

constexpr char PROMPT_ARG_SHORT = 'p';
constexpr __UINT64_TYPE__ PROMPT_ARG = stringHash("--prompt");
constexpr __UINT64_TYPE__ WIDTH_ARG_SHORT = stringHash("-w");
constexpr __UINT64_TYPE__ WIDTH_ARG = stringHash("--width");
constexpr __UINT64_TYPE__ HEIGHT_ARG_SHORT = stringHash("-h");
constexpr __UINT64_TYPE__ HEIGHT_ARG = stringHash("--height");
constexpr __UINT64_TYPE__ WORDC_ARG_SHORT = stringHash("-c");
constexpr __UINT64_TYPE__ WORDC_ARG = stringHash("--count");
constexpr __UINT64_TYPE__ FIRST_ARG_SHORT = stringHash("-f");
constexpr __UINT64_TYPE__ FIRST_ARG = stringHash("--first");
constexpr __UINT64_TYPE__ ITERATIONS_ARG_SHORT = stringHash("-i");
constexpr __UINT64_TYPE__ ITERATIONS_ARG = stringHash("--iterations");
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
constexpr __UINT64_TYPE__ TARGET_ARG_SHORT = stringHash("-t");
constexpr __UINT64_TYPE__ TARGET_ARG = stringHash("--target");

int main(int argc, char** argv)
{
    //enableConsoleProcessing();
    characterSet_UTF8();
    //consoleCodePage_utf8();

    const int defaultValue = 0;
    const int defaultBool = 0;
    const size_t defaultIterations = 1;
    const size_t defaultTargetWordLength = __SIZE_MAX__;

    int promptBool = argc <= 1;
    int width = defaultValue;
    int height = defaultValue;
    size_t wordCount = defaultValue;
    int startingChar = defaultValue;
    size_t iterations = defaultIterations;
    char* listFileName = (char*)"wordQuestions.txt";
    char* outputFileName = NULL;
    int randomBool = defaultBool;
    int deterministicBool = defaultBool;
    __UINT64_TYPE__ seed = defaultValue;
    size_t targetWordLength = defaultTargetWordLength;

    enum argsMode mode = noArg;

    for (typeof(argc) i = 0; i < argc; i++)
    {
        switch (stringHash_nullTerminated(argv[i]))
        {
        case PROMPT_ARG:
            promptBool = 1;
            break;

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

        case ITERATIONS_ARG_SHORT:
        case ITERATIONS_ARG:
            mode = iterationsArg;
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

        case TARGET_ARG_SHORT:
        case TARGET_ARG:
            mode = targetArg;
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
                        case PROMPT_ARG_SHORT:
                            promptBool = 1;
                            break;

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

            case iterationsArg:
                if (1 == sscanf(argv[i], " %zu", &iterations)) mode = noArg;
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

            case targetArg:
                if (1 == sscanf(argv[i], " %zu", &targetWordLength)) mode = noArg;
            
            default:
                break;
            }
            break;
        }
        
        
    }

    //User inputs
    if (width <= 0)
    {
        printf("\nEnter width:");
        valRead_intDest(&width, "\007\nInput must be an integer:");
    }

    if (height <= 0)
    {
        printf("\nEnter height:");
        valRead_intDest(&height, "\007\nInput must be an integer:");
    }

    if (wordCount <= 0)
    {
        printf("\nEnter wordCount:");
        valRead_size_tDest(&wordCount, "\007\nInput must be an integer:");
    }

    if (startingChar == defaultValue)
    {
        printf("\nEnter starting character:");
        valRead_wcharDest(&startingChar, "\007\nInput must be an character:");
    }

    if (promptBool)
    {
        if (iterations == defaultIterations)
        {
            printf("\nEnter the number of iterations to create:");
            valRead_size_tDest(&iterations, "\007\nInput must be an integer:");
        }

        if (randomBool == defaultBool)
        {
            printf("\nRandomization? ");
            clearInput_untilNewLine();
            randomBool = rawReadBool('y', 'n');
        }

        if (randomBool)
        {
            if (deterministicBool == defaultBool)
            {
                printf("\nDeterministic? ");
                clearInput_untilNewLine();
                deterministicBool = rawReadBool('y', 'n');
            }

            if (seed == defaultValue)
            {
                char inputArray[256];
                printf("\nSeed:");
                clearInput_untilNewLine();
                char* front = fgets(inputArray, sizeof(inputArray), stdin);
                seed = stringHash(inputArray, stringConstexpr_match(inputArray, '\n'));
            }
        }

        if (targetWordLength == defaultTargetWordLength)
        {
            printf("\nEnter the target word length:");
            valRead_size_tDest(&targetWordLength, "\007\nInput must be an integer:");
        }
    }

    //Main run
    if (deterministicBool) randomTable_indicesFromTable();

    FILE *outputStream = stdout;

    if (outputFileName != NULL)
    {
        outputStream = fileUtility_open(outputFileName, "a");
    }

    for (size_t i = 0; i < iterations; i++)
    {
        fprintTime_ymd(outputStream);
        fprintf(outputStream, "\n");
        crossword(outputStream, width, height, wordCount, startingChar, listFileName, randomBool, seed, targetWordLength);
    }
    
    if (outputFileName != NULL)
    {
        fclose(outputStream);
    }

    if (outputStream == stdout)
    {
        fprintf(outputStream, "Press any key to close...\n");
        clearInput_untilNewLine();
        rawRead();
    }
    
}
