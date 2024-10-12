#ifndef CHAR_ARRAY_PAIR_ARRAY_
#define CHAR_ARRAY_PAIR_ARRAY_

#include <stdlib.h>

void charArrayPairArray_free(void *array, const size_t count);

void charArrayPairArray_swap(void *array, const size_t count, const size_t firstIndex, const size_t secondIndex);
void charArrayPairArray_shuffle(void *array, const size_t count);

void charArrayPairArray_quicksort_firstLengthAccending(void *array, const size_t count);

void charArrayPairArray_printAsChar(void *array, const size_t count);

#endif //CHAR_ARRAY_PAIR_ARRAY_