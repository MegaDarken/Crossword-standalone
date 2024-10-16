#ifndef SHUFFLE_
#define SHUFFLE_

#include "swapping.h"
#include "randomTable.h"

#define shuffle_helper(_1, _2, _3, NAME, ...) NAME

#define shuffle_known(array, count) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( int i = 0; i < _count; i++ ) { \
        swap(&array[i], &array[(getRandomUInt() % _count)]); \
        } \
    } while(0)

#define shuffle_size(array, count, elementSize) \
    do { \
        __typeof__ (count) _count = (count);\
        size_t index = array;\
        for ( size_t i = 0; i < _count; i++ ) { \
        swap(index, array + ((getRandomUInt() % _count) * elementSize), elementSize); \
        index += elementSize;\
        } \
    } while(0)

#define shuffle(...) shuffle_helper(__VA_ARGS__, shuffle_size, shuffle_known)(__VA_ARGS__)

#endif //SHUFFLE_
