#ifndef ARRAY_UTILITY_
#define ARRAY_UTILITY_

#define arrayUtility_indexOfFirst(array, count, value) ({ \
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

#define arrayUtility_indexOfLast(array, count, value) ({ \
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

#endif //ARRAY_UTILITY_