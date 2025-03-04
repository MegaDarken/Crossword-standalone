#ifndef ARRAY_INDEX_UTILITY_
#define ARRAY_INDEX_UTILITY_

#include "loopUtility.h"

#define arrayIndexUtility_first(array, count, value) ({ \
    size_t output; \
    do { \
        __typeof__ (count) _count = (count);\
        __typeof__ (value) _value = (value);\
        for ( size_t i = 0; i < _count; i++ ) { \
            if ( array[i] == _value ) { \
                output = i; \
                break; \
            } \
        } \
    } while(0); \
    output; })

#define arrayIndexUtility_last(array, count, value) ({ \
    size_t output; \
    do { \
        __typeof__ (count) _count = (count);\
        __typeof__ (value) _value = (value);\
        for ( size_t i = _count - 1; i >= 0 ; i-- ) { \
            if ( array[i] == _value ) { \
                output = i; \
                break; \
            } \
        } \
    } while(0); \
    output; })

#endif //ARRAY_INDEX_UTILITY_