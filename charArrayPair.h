#ifndef CHAR_ARRAY_PAIR_
#define CHAR_ARRAY_PAIR_

#include "charArray.h"

struct charArrayPair
{
    struct charArray first;
    struct charArray second;
};

void charArrayPair_createDest(struct charArrayPair *dest, const int firstCount, const int secondCount);
void charArrayPair_createEmptyDest(struct charArrayPair *dest);
struct charArrayPair charArrayPair_create(const int firstCount, const int secondCount);
struct charArrayPair charArrayPair_createEmpty();

void charArrayPair_free(struct charArrayPair *var);

void charArrayPair_splitArray_onFirstValue(struct charArrayPair *var, const char *inputArray, const size_t inputCount, char value);
void charArrayPair_split_onFirstValue(struct charArrayPair *var, struct charArray *input, char value);
void charArrayPair_splitArray_onLastValue(struct charArrayPair *var, const char *inputArray, const size_t inputCount, char value);
void charArrayPair_split_onLastValue(struct charArrayPair *var, struct charArray *input, char value);

void charArrayPair_printAsChar(struct charArrayPair *var);

#endif //CHAR_ARRAY_