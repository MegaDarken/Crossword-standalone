#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include <stdlib.h>

void insertionSort_ascending(void* array, const size_t count, const size_t elementSize, void* firstElementComparisonPtr);
void insertionSort_descending(void* array, const size_t count, const size_t elementSize, void* firstElementComparisonPtr);

#endif // __INSERTION_SORT__