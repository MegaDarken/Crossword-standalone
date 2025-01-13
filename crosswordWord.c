#include "crosswordWord.h"

#include <string.h>

void crosswordPlacedWord_none(struct crosswordPlacedWord *var)
{
    memset(&var->pair, 0, sizeof(var->pair));
    var->originalPairIndex = -1;
    var->flag = none;
    var->gridIndex = -1;
}