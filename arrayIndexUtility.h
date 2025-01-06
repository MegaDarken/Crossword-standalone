#ifndef ARRAY_INDEX_UTILITY_
#define ARRAY_INDEX_UTILITY_

#include "arrayUtility.h"

#define arrayIndexUtility_first(array, count, value) ({ \
    size_t output; \
    __typeof__ (value) _value = (value); \
    arrayUtility_checkBreakEach(array, count, array[i] == _value, output = i); \
    output; })

#define arrayIndexUtility_last(array, count, value) ({ \
    size_t output; \
    __typeof__ (value) _value = (value); \
    arrayUtility_checkBreakEachDescending(array, count, array[i] == _value, output = i); \
    output; })

#endif //ARRAY_INDEX_UTILITY_