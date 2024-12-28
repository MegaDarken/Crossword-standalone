#include "crossword.h"

#include <stdio.h>
#include <wchar.h>
#include <ctype.h>

#include "fileUtility.h"
#include "charArraySplit.h"
#include "charArrayPairArray.h"
#include "charGrid.h"
#include "swapping.h"
#include "boxDrawing.h"
#include "insertionSort.h"
#include "seedyShuffle.h"
#include "memMacro.h"


void crossword_loadWords(struct arrayList *list, const char *filename, char splitValue)
{
    FILE* inf;
    inf = fileUtility_open(filename, "r");

    char buffer[256];
    size_t bufferSize = sizeof(buffer);

    do
    {
        bufferSize = fileUtility_charBufferGetUntil(buffer, sizeof(buffer), '\n', inf);

        //printf("%.*s\n", bufferSize, buffer);//Print for debug
    
        if(bufferSize > 2)
        {
            struct charArrayPair pair = charArrayPair_createEmpty();
            charArrayPair_splitArray_onFirstValue(&pair, buffer, bufferSize - 1, splitValue);
            charArray_toupper(&pair.first);
            arrayList_append(list, &pair);
        }
        else
        {
            break;
        }
    } 
    while (buffer[bufferSize - 1] != EOF);

    fclose(inf);
}

int crossword_adjacentAcrossValid(struct charGrid *letters, const size_t index)
{
    size_t mod = index % letters->width;
    return (mod == 0 
    || letters->array.array[index-1] == ' ')
    && (mod == letters->width - 1
    || letters->array.array[index+1] == ' ');
}

int crossword_adjacentDownValid(struct charGrid *letters, const size_t index)
{
    return (charGrid_indexTopRow(letters, index) 
    || letters->array.array[index - letters->width] == ' ')
    && (charGrid_indexBottomRow(letters, index)
    || letters->array.array[index + letters->width] == ' ');
}

void crossword_maxBoundsAcross(struct charGrid *letters, const size_t index, size_t *beforeCount, size_t *afterCount)
{
    *beforeCount = index % letters->width;
    *afterCount = (letters->width) - *beforeCount;

    size_t currentIndex = index;
    for (size_t i = 1; i <= *beforeCount; i++)
    {
        currentIndex--;

        if ((letters->array.array[currentIndex] == ' '
        && !crossword_adjacentDownValid(letters, currentIndex))
        || (letters->array.array[currentIndex] != ' '
        && !crossword_adjacentAcrossValid(letters, currentIndex)))
        {
            *beforeCount = i - 1;
            break;
        }
    }

    currentIndex = index;
    for (size_t i = 1; i <= *afterCount; i++)
    {
        currentIndex++;

        if ((letters->array.array[currentIndex] == ' '
        && !crossword_adjacentDownValid(letters, currentIndex))
        || (letters->array.array[currentIndex] != ' '
        && !crossword_adjacentAcrossValid(letters, currentIndex)))
        {
            *afterCount = i - 1;
            break;
        }
    }
    
}

void crossword_maxBoundsDown(struct charGrid *letters, const size_t index, size_t *beforeCount, size_t *afterCount)
{
    *beforeCount = index / letters->width;
    *afterCount = (letters->height) - *beforeCount;

    size_t currentIndex = index;
    for (size_t i = 1; i <= *beforeCount; i++)
    {
        currentIndex -= letters->width;

        if ((letters->array.array[currentIndex] == ' '
        && !crossword_adjacentAcrossValid(letters, currentIndex))
        || (letters->array.array[currentIndex] != ' '
        && !crossword_adjacentDownValid(letters, currentIndex)))
        {
             *beforeCount = i - 1;
            break;
        }
    }

    currentIndex = index;
    for (size_t i = 1; i <= *afterCount; i++)
    {
        currentIndex += letters->width;

        if ((letters->array.array[currentIndex] == ' '
        && !crossword_adjacentAcrossValid(letters, currentIndex))
        || (letters->array.array[currentIndex] != ' '
        && !crossword_adjacentDownValid(letters, currentIndex)))
        {
            *afterCount = i - 1;
            break;
        }
    }
    
}

int crossword_matchesExistingAcross(struct charGrid *letters, const size_t index, const struct charArray *word)
{
    if((!charGrid_indexLeftColumn(letters, index)
    && letters->array.array[index - 1] != ' ')
    || (!charGrid_indexRightColumn(letters, index + word->count - 1)
    && letters->array.array[index + word->count] != ' '))
    {
        return 0;
    }

    for (size_t i = 0; i < word->count; i++)
    {
        if (letters->array.array[i + index] != ' '
        && letters->array.array[i + index] != word->array[i])
        {
            return 0;
        }
    }

    return 1;
    
}

int crossword_matchesExistingDown(struct charGrid *letters, const size_t index, const struct charArray *word)
{
    size_t currentIndex = index;

    for (size_t i = 0; i < word->count; i++)
    {
        if (letters->array.array[currentIndex] != ' '
        && letters->array.array[currentIndex] != word->array[i])
        {
            return 0;
        }

        currentIndex += letters->width;
    }

    if ((charGrid_indexTopRow(letters, index)
    || letters->array.array[index - letters->width] == ' ')
    && (charGrid_indexBottomRow(letters, currentIndex)
    || letters->array.array[currentIndex] == ' '))
    {
        return 1;
    }

    return 0;
    
}

struct crosswordPlacedWord crossword_searchListAcross(struct arrayList *wordList, struct charGrid *letters, const size_t index, const size_t wordListStart)
{
    size_t beforeCount;
    size_t afterCount;

    crossword_maxBoundsAcross(letters, index, &beforeCount, &afterCount);

    if (beforeCount == 0
    && afterCount == 0)
    {
        struct crosswordPlacedWord output = { .pair = -1, .originalPairIndex = -1, .flag = none, .gridIndex = -1 };
        return output;
    }
    

    struct charArrayPair *currentWord;
    size_t occuranceArray[16];

    for (size_t i = wordListStart; i < wordList->count; i++)
    {
        currentWord = (struct charArrayPair *)arrayList_get(wordList, i);
        
        size_t occuranceCount = charArray_indicesOfValue(&currentWord->first, occuranceArray, sizeof(occuranceArray), letters->array.array[index]);

        for (size_t j = 0; j < occuranceCount; j++)
        {

            if (occuranceArray[j] <= beforeCount
            && currentWord->first.count - occuranceArray[j] <= afterCount
            && crossword_matchesExistingAcross(letters, index - occuranceArray[j], &currentWord->first))
            {
                charGrid_setHorizontal_array(letters, (index % letters->width) - occuranceArray[j], index / letters->width, currentWord->first.array, currentWord->first.count);

                struct crosswordPlacedWord output = { .pair = *currentWord, .originalPairIndex = i, .flag = across, .gridIndex = index - occuranceArray[j] };
                return output;
            }
            
            if (occuranceArray[j] > beforeCount)
            {
                j = occuranceCount;
            }
        }
          
    }

    struct crosswordPlacedWord output = { .pair = -1, .originalPairIndex = -1, .flag = none, .gridIndex = -1 };
    return output;
}

struct crosswordPlacedWord crossword_searchListDown(struct arrayList *wordList, struct charGrid *letters, const size_t index, const size_t wordListStart)
{
    size_t beforeCount;
    size_t afterCount;

    crossword_maxBoundsDown(letters, index, &beforeCount, &afterCount);

    if (beforeCount == 0
    && afterCount == 0)
    {
        struct crosswordPlacedWord output = { .pair = -1, .originalPairIndex = -1, .flag = none, .gridIndex = -1 };
        return output;
    }

    struct charArrayPair *currentWord;
    size_t occuranceArray[16];

    for (size_t i = wordListStart; i < wordList->count; i++)
    {
        currentWord = (struct charArrayPair *)arrayList_get(wordList, i);
        
        size_t occuranceCount = charArray_indicesOfValue(&currentWord->first, occuranceArray, sizeof(occuranceArray), letters->array.array[index]);

        for (size_t j = 0; j < occuranceCount; j++)
        {

            if (occuranceArray[j] <= beforeCount
            && currentWord->first.count - occuranceArray[j] <= afterCount
            && crossword_matchesExistingDown(letters, index - (occuranceArray[j] * letters->width), &currentWord->first))
            {
                charGrid_setVertical_array(letters, index % letters->width, (index / letters->width) - occuranceArray[j], currentWord->first.array, currentWord->first.count);

                struct crosswordPlacedWord output = { .pair = *currentWord, .originalPairIndex = i, .flag = down, .gridIndex = index - (occuranceArray[j] * letters->width) };
                return output;
            }

            if (occuranceArray[j] > beforeCount)
            {
                j = occuranceCount;
            }
            
        }
          
    }

    struct crosswordPlacedWord output = { .pair = -1, .originalPairIndex = -1, .flag = none, .gridIndex = -1 };
    return output;
}

void crossword_searchListAtIndex(const size_t wordCount, struct arrayList *wordList, struct charGrid *letters, const size_t index, struct crosswordPlacedWord *usedWordArray, size_t *wordListStart)
{
    if (letters->array.array[index] != ' ')
    {
            int acrossValid = crossword_adjacentAcrossValid(letters, index);

        if (acrossValid)
        {
            struct crosswordPlacedWord val = crossword_searchListAcross(wordList, letters, index, *wordListStart);

            if (val.flag != none)
            {
                usedWordArray[*wordListStart] = val;
                charArrayPairArray_swap(wordList->array, wordList->count, val.originalPairIndex, *wordListStart);
                (*wordListStart)++;

                // charArrayPairArray_printAsChar(wordList->array, wordList->count);
                // charGrid_printAsChars(letters);
                // rawRead();
            }

        }

        if (*wordListStart >= wordCount)
        {
            return;
        }

        int downValid = crossword_adjacentDownValid(letters, index);
        
        if (downValid)
        {
            struct crosswordPlacedWord val = crossword_searchListDown(wordList, letters, index, *wordListStart);

            if (val.flag != none)
            {
                usedWordArray[*wordListStart] = val;
                charArrayPairArray_swap(wordList->array, wordList->count, val.originalPairIndex, *wordListStart);
                (*wordListStart)++;

                // charArrayPairArray_printAsChar(wordList->array, wordList->count);
                // charGrid_printAsChars(letters);
                // rawRead();
            }
        }

    }
}

void crossword_insertionSort_crosswordPlacedWordArray_gridIndexAscending(struct crosswordPlacedWord *array, const size_t count)
{
    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = i; j > 0 && array[j-1].gridIndex > array[j].gridIndex; j--)
        {
            swap(&array[j-1], &array[j]);
        }
        
    }
    
}

void crossword_fprintEntry(FILE *stream, struct charGrid *letters, struct charGrid *numbers, const size_t x, const size_t y)
{
    char letter = charGrid_get(letters, x, y);

    if (letter == ' ')
    {
        fwprintf(stream, L"▒▒▒▒");
    }
    else
    {
        char number = charGrid_get(numbers, x, y);

        if (number == 0)
        {
            fwprintf(stream, L"    ");
        }
        else
        {
            fwprintf(stream, L"%-4u", (unsigned char)number);
        }
    }
}

void crossword_fprintEntryPad(FILE *stream, struct charGrid *letters, struct charGrid *numbers, const size_t x, const size_t y)
{
    char letter = charGrid_get(letters, x, y);

    if (letter == ' ')
    {
        fwprintf(stream, L"▒▒▒▒");
    }
    else
    {
        fwprintf(stream, L"    ");
    }
}

void crossword_fprintGrid(FILE *stream, struct charGrid *letters, struct charGrid *numbers)
{
    if (letters->width != numbers->width || letters->height != numbers->height)
    {
        return;
    }

    const __WCHAR_TYPE__ *vert = boxDrawing_value(noLine, noLine, standardLine, standardLine);

    boxDrawing_fprint_intervalHorizontalLine(stream, standardLine, noLine, standardLine, letters->width + 1, 4);
    fwprintf(stream, L"\n");
    fwprintf(stream, L"%ls", vert);

    for (size_t x = 0; x < letters->width; x++)
    {
        crossword_fprintEntry(stream, letters, numbers, x, 0);
        fwprintf(stream, L"%ls", vert);
    }

    fwprintf(stream, L"\n");
    fwprintf(stream, L"%ls", vert);

    for (size_t x = 0; x < letters->width; x++)
    {
        crossword_fprintEntryPad(stream, letters, numbers, x, 0);
        fwprintf(stream, L"%ls", vert);
    }

    fwprintf(stream, L"\n");
    
    for (size_t y = 1; y < letters->height; y++)
    {
        boxDrawing_fprint_intervalHorizontalLine(stream, standardLine, standardLine, standardLine, letters->width + 1, 4);
        fwprintf(stream, L"\n");
        fwprintf(stream, L"%ls", vert);

        for (size_t x = 0; x < letters->width; x++)
        {
            crossword_fprintEntry(stream, letters, numbers, x, y);
            fwprintf(stream, L"%ls", vert);
        }
        
        fwprintf(stream, L"\n");
        fwprintf(stream, L"%ls", vert);

        for (size_t x = 0; x < letters->width; x++)
        {
            crossword_fprintEntryPad(stream, letters, numbers, x, y);
            fwprintf(stream, L"%ls", vert);
        }

        fwprintf(stream, L"\n");
    }
    
    boxDrawing_fprint_intervalHorizontalLine(stream, standardLine, standardLine, noLine, letters->width + 1, 4);
    fwprintf(stream, L"\n");
}

void crossword_fprint(FILE *stream, struct charGrid *letters, struct crosswordPlacedWord *usedWordArray, const size_t placedWordCount)
{
    struct charGrid flags = charGrid_create(letters->width, letters->height);
    charArray_setAll(&flags.array, 0);

    size_t currentNumber = 0;
    size_t currentIndex = -1;

    fwprintf(stream, L"Across\n");
    for (size_t i = 0; i < placedWordCount; i++)
    {
        if (currentIndex != usedWordArray[i].gridIndex)
        {
            currentIndex = usedWordArray[i].gridIndex;
            currentNumber++;
        }

        if (usedWordArray[i].flag == across)
        {
            fwprintf(stream, L"%zu: ", currentNumber);
            charArray_fwprintAsChar(stream, &usedWordArray[i].pair.second);
            fwprintf(stream, L" (%zu)", usedWordArray[i].pair.first.count);
            fwprintf(stream, L"\n");
        }
        
        flags.array.array[usedWordArray[i].gridIndex] = currentNumber;
    }
    
    fwprintf(stream, L"Down\n");
    for (size_t i = 0; i < placedWordCount; i++)
    {
        if (usedWordArray[i].flag == down)
        {
            fwprintf(stream, L"%d: ", flags.array.array[usedWordArray[i].gridIndex]);
            charArray_fwprintAsChar(stream, &usedWordArray[i].pair.second);
            fwprintf(stream, L" (%zu)", usedWordArray[i].pair.first.count);
            fwprintf(stream, L"\n");
        }
        
    }

    crossword_fprintGrid(stream, letters, &flags);

    charGrid_free(&flags);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void crossword(FILE *stream, const int width, const int height, const size_t wordCount, const int startingChar, const char* listFileName, const int randomBool, const __UINT64_TYPE__ seed)
{
    struct arrayList *fullWordList = NULL;
    memMacro_malloc(fullWordList);
    *fullWordList = arrayList_create(0, sizeof(struct charArrayPair));

    crossword_loadWords(fullWordList, listFileName, ';');
    //charArrayPairArray_printAsChar(fullWordList->array, fullWordList->count);

    struct charArrayPair *pairArray = fullWordList->array;

    if (randomBool)
    {
        seedyShuffle(pairArray, fullWordList->count, seed);
    }
    else
    {
        insertionSort_descending(fullWordList->array, fullWordList->count, fullWordList->elementSize, &((struct charArrayPair *)fullWordList->array)->first.count);
    }

    // charArrayPairArray_free(fullWordList->array, fullWordList->count);

    //charArrayPairArray_printAsChar(fullWordList->array, fullWordList->count);

    // charArrayPairArray_printAsChar(fullWordList->array, fullWordList->count);
    // fwprintf(stream, L"\n%x ", fullWordList->count);

    struct crosswordPlacedWord *usedWordArray;
    memMacro_mallocArray(usedWordArray, wordCount);

    struct charGrid *letters = NULL;
    memMacro_malloc(letters);
    *letters = charGrid_create(width, height);
    
    charArray_setAll(&letters->array, ' ');

    charGrid_set(letters, letters->width >> 1, letters->height >> 1, toupper(startingChar));

    size_t placedWordCount = 0;
    for (int i = 0; i < wordCount && placedWordCount < wordCount; i++)
    {
        for (size_t j = 0; j < letters->array.count && placedWordCount < wordCount; j++)
        {
            crossword_searchListAtIndex(wordCount, fullWordList, letters, j, usedWordArray, &placedWordCount);            
        }
        
    }

    //crossword_insertionSort_crosswordPlacedWordArray_gridIndexAscending(usedWordArray, placedWordCount);
    insertionSort_ascending(usedWordArray, placedWordCount, sizeof(usedWordArray[0]), &usedWordArray[0].gridIndex);

    crossword_fprint(stream, letters, usedWordArray, placedWordCount);

    charGrid_fwprintAsChars(stream, letters);

    //charArrayPairArray_printAsChar(fullWordList->array, fullWordList->count);

    charArrayPairArray_free(fullWordList->array, fullWordList->count);
    arrayList_free(fullWordList);

    charGrid_free(letters);

    free(letters);
    free(usedWordArray);
    free(fullWordList);
}