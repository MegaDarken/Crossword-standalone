#ifndef SEEDY_SHUFFLE_
#define SEEDY_SHUFFLE_

#include "swapping.h"
#include "randomTable.h"

#define seedyShuffle_helper(_1, _2, _3, _4, NAME, ...) NAME

#define seedyShuffle_known(array, count, seed) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( __typeof__ (_count) i = 0; i < _count; i++ ) { \
        swap(&array[i], &array[(getSeedyRandomU(seed) % _count)]); \
        } \
    } while(0)

#define seedyShuffle_size(array, count, seed, elementSize) \
    do { \
        __typeof__ (count) _count = (count);\
        void* index = array;\
        for ( __typeof__ (_count) i = 0; i < _count; i++ ) { \
        swap(index, array + ((getSeedyRandomU(seed) % _count) * elementSize), elementSize); \
        index += elementSize;\
        } \
    } while(0)

#define seedyShuffle(...) shuffle_helper(__VA_ARGS__, seedyShuffle_size, seedyShuffle_known)(__VA_ARGS__)

#endif //SEEDY_SHUFFLE_