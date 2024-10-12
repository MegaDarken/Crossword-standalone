#ifndef CHAR_ARRAY_SPLIT_
#define CHAR_ARRAY_SPLIT_

#include <stdio.h>

#include "charArray.h"

void charArraySplit_array_before(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index);
void charArraySplit_before(struct charArray *input, struct charArray *first, struct charArray *second, size_t index);
void charArraySplit_array_after(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index);
void charArraySplit_after(struct charArray *input, struct charArray *first, struct charArray *second, size_t index);
void charArraySplit_array_on(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index);
void charArraySplit_on(struct charArray *input, struct charArray *first, struct charArray *second, size_t index);

size_t charArraySplit_array_onFirstValue(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, char value);
size_t charArraySplit_onFirstValue(struct charArray *input, struct charArray *first, struct charArray *second, char value);
size_t charArraySplit_array_onLastValue(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, char value);
size_t charArraySplit_onLastValue(struct charArray *input, struct charArray *first, struct charArray *second, char value);

#endif //CHAR_ARRAY_SPLIT_