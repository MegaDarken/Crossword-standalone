#ifndef _CROSSWORD_WORD_
#define _CROSSWORD_WORD_

#include <stddef.h>

#include "charArrayPair.h"

enum crosswordFlag{none, across, down, acrossAndDown};

struct crosswordPlacedWord
{
    struct charArrayPair pair;
    size_t originalPairIndex;
    enum crosswordFlag flag;
    size_t gridIndex;   
};

void crosswordPlacedWord_none(struct crosswordPlacedWord *var);

#endif //_CROSSWORD_WORD_