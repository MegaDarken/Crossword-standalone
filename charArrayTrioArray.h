#ifndef CHAR_ARRAY_TRIO_ARRAY_
#define CHAR_ARRAY_TRIO_ARRAY_

#include <stdlib.h>

void charArrayTrioArray_free(void *array, const size_t count);

void charArrayTrioArray_swap(void *array, const size_t count, const size_t firstIndex, const size_t secondIndex);

void charArrayTrioArray_quicksort_firstLengthAccending(void *array, const size_t count);

void charArrayTrioArray_printAsChar(void *array, const size_t count);

#endif //CHAR_ARRAY_PAIR_ARRAY_