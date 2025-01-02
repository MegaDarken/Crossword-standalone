#ifndef CROSSWORD_
#define CROSSWORD_

#include <stddef.h>

#include "arrayList.h"
#include "charGrid.h"
#include "charArrayPair.h"

enum crosswordFlag{none, across, down, acrossAndDown};

struct crosswordPlacedWord
{
    struct charArrayPair pair;
    size_t originalPairIndex;
    enum crosswordFlag flag;
    size_t gridIndex;   
};

void crossword_loadWords(struct arrayList *list, const char *filename, char splitValue);

int crossword_adjacentAcrossValid(struct charGrid *letters, const size_t index);
int crossword_adjacentDownValid(struct charGrid *letters, const size_t index);

void crossword_maxBoundsAcross(struct charGrid *letters, const size_t index, size_t *beforeCount, size_t *afterCount);
void crossword_maxBoundsDown(struct charGrid *letters, const size_t index, size_t *beforeCount, size_t *afterCount);

int crossword_matchesExistingAcross(struct charGrid *letters, const size_t index, const struct charArray *word);
int crossword_matchesExistingDown(struct charGrid *letters, const size_t index, const struct charArray *word);

struct crosswordPlacedWord crossword_searchListAcross(struct arrayList *wordList, struct charGrid *letters, const size_t index, const size_t wordListStart, const size_t targetLength);
struct crosswordPlacedWord crossword_searchListDown(struct arrayList *wordList, struct charGrid *letters, const size_t index, const size_t wordListStart, const size_t targetLength);

void crossword_searchListAtIndex(const size_t wordCount, struct arrayList *wordList, struct charGrid *letters, const size_t index, struct crosswordPlacedWord *usedWordArray, size_t *wordListStart, const size_t targetLength);

void crossword_insertionSort_crosswordPlacedWordArray_gridIndexAscending(struct crosswordPlacedWord *array, const size_t count);

void crossword_fprintEntry(FILE *stream, struct charGrid *letters, struct charGrid *numbers, const size_t x, const size_t y);
void crossword_fprintGrid(FILE *stream, struct charGrid *letters, struct charGrid *numbers);

void crossword_fprint(FILE *stream, struct charGrid *letters, struct crosswordPlacedWord *usedWordArray, const size_t placedWordCount);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void crossword(FILE *stream, const int width, const int height, const size_t wordCount, const int startingChar, const char* listFileName, const int randomBool, const __UINT64_TYPE__ seed, const size_t targetWordLength);

#endif //CROSSWORD_