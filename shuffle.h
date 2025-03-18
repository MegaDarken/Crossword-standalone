#ifndef SHUFFLE_
#define SHUFFLE_

#include "swapping.h"
#include "randomTable.h"

#define shuffle_helper(_1, _2, _3, NAME, ...) NAME

#define shuffle_known(array, count) \
    do { \
        __typeof__ (array) _array = (array);\
        __typeof__ (count) _count = (count);\
        for ( __typeof__ (_count) i = 0; i < _count; i++ ) { \
            swap(&(_array[i]), &(_array[(getRandomU(__typeof__ (_count)) % _count)])); \
        } \
    } while(0)

#define shuffle_size(array, count, elementSize) \
    do { \
        __typeof__ (array) _array = (array);\
        __typeof__ (count) _count = (count);\
        __typeof__ (elementSize) _elementSize = (elementSize);\
        void* _index = _array;\
        for ( __typeof__ (_count) _i = 0; _i < _count; _i++ ) { \
            swap(_index, (_array + ((getRandomU(__typeof__ (_count)) % _count) * _elementSize)), _elementSize); \
            _index += _elementSize;\
        } \
    } while(0)

#define shuffle(...) shuffle_helper(__VA_ARGS__, shuffle_size, shuffle_known)(__VA_ARGS__)

#endif //SHUFFLE_
