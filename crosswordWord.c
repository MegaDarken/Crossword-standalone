#include "crosswordWord.h"

#include <string.h>

#include "spansUtility.h"

void crosswordPlacedWord_none(struct crosswordPlacedWord *var)
{
    memset(&var->pair, 0, sizeof(var->pair));
    var->originalPairIndex = -1;
    var->flag = none;
    var->gridIndex = -1;
}

void crosswordWord_fwprintLetterCount(FILE *stream, struct charArray *var)
{
    size_t spansArray[var->count];

    spans(var->array, var->count, spansArray, isspace(var->array[_loopIndex])); 

    size_t index = isspace(var->array[0]);

    for (; index < var->count; index += 2)
    {
        if (!spansArray[index])
        {
            break;
        }
        
        fwprintf(stream, L"%u", spansArray[index]);

        if (index + 2 < var->count && spansArray[index + 2])
        {
            fwprintf(stream, L",");
        }
    }
}
