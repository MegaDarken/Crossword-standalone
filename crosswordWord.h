#ifndef _CROSSWORD_WORD_
#define _CROSSWORD_WORD_

#include <stddef.h>

#include "charArrayTrio.h"

enum crosswordFlag{none, across, down, acrossAndDown};

struct crosswordPlacedWord
{
    struct charArrayTrio pair;
    size_t originalPairIndex;
    enum crosswordFlag flag;
    size_t gridIndex;   
};

void crosswordPlacedWord_none(struct crosswordPlacedWord *var);

void crosswordWord_letterCounts(struct charArray *var, struct charArray *dest);

#endif //_CROSSWORD_WORD_