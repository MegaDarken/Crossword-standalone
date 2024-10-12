//Imports
#include "charArrayPair.h"

#include "charArraySplit.h"

//Methods
void charArrayPair_createDest(struct charArrayPair *dest, const int firstCount, const int secondCount)
{
    dest->first = charArray_create(firstCount);
    dest->second = charArray_create(secondCount);
}

void charArrayPair_createEmptyDest(struct charArrayPair *dest)
{
    dest->first = charArray_create(0);
    dest->second = charArray_create(0);
}

struct charArrayPair charArrayPair_create(const int firstCount, const int secondCount)
{
    struct charArrayPair val = {};

    charArrayPair_createDest(&val, firstCount, secondCount);

    return val;
}

struct charArrayPair charArrayPair_createEmpty()
{
    struct charArrayPair val = {};

    charArrayPair_createEmptyDest(&val);

    return val;
}

void charArrayPair_free(struct charArrayPair *var)
{
    charArray_free(&var->first);
    charArray_free(&var->second);
}

void charArrayPair_splitArray_onFirstValue(struct charArrayPair *var, const char *inputArray, const size_t inputCount, char value)
{
    charArraySplit_array_onFirstValue(inputArray, inputCount, &var->first, &var->second, value);
}

void charArrayPair_split_onFirstValue(struct charArrayPair *var, struct charArray *input, char value)
{
    charArraySplit_onFirstValue(input, &var->first, &var->second, value);
}

void charArrayPair_splitArray_onLastValue(struct charArrayPair *var, const char *inputArray, const size_t inputCount, char value)
{
    charArraySplit_array_onLastValue(inputArray, inputCount, &var->first, &var->second, value);
}

void charArrayPair_split_onLastValue(struct charArrayPair *var, struct charArray *input, char value)
{
    charArraySplit_onFirstValue(input, &var->first, &var->second, value);
}

void charArrayPair_printAsChar(struct charArrayPair *var)
{
    charArray_printAsChar(&var->first);
    putchar('|');
    charArray_printAsChar(&var->second);
}
