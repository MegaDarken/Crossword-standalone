#include "crosswordWord.h"

#include <string.h>
#include <ctype.h>

#include "spansUtility.h"

void crosswordPlacedWord_none(struct crosswordPlacedWord *var)
{
    memset(&var->pair, 0, sizeof(var->pair));
    var->originalPairIndex = -1;
    var->flag = none;
    var->gridIndex = -1;
}

void crosswordWord_letterCounts(struct charArray *var, struct charArray *dest)
{
    size_t spansArray[var->count];

    spans(var->array, var->count, spansArray, isspace(var->array[_loopIndex]));

    size_t outputCount = var->count;

    for (size_t i = 0; i < var->count; i++)
    {
        if (!spansArray[i])
        {
            outputCount = i;
            break;
        }
    }

    charArray_resize(dest, (outputCount >> 1) + 1);

    size_t index = isspace(var->array[0]);
    size_t outdex = 0;

    for (; index < var->count && spansArray[index]; index += 2)
    {   
        dest->array[outdex] = spansArray[index];

        outdex++;
    }
}

int crosswordPlacedWord_comparGridIndex(const void * a, const void * b)
{
    struct crosswordPlacedWord *arg1 = (struct crosswordPlacedWord *)a;
    struct crosswordPlacedWord *arg2 = (struct crosswordPlacedWord *)b;

    return arg1->gridIndex - arg2->gridIndex;
}
