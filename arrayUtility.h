#ifndef ARRAY_UTILITY_
#define ARRAY_UTILITY_

#define arrayUtility_each(array, count, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = 0; i < _count; i++ ) { \
            expression; \
        } \
    } while(0);

#define arrayUtility_eachDescending(array, count, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = _count - 1; i >= 0 ; i-- ) { \
            expression; \
        } \
    } while(0);

#define arrayUtility_checkEach(array, count, check, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = 0; i < _count; i++ ) { \
            if (check) { \
                expression; \
            } \
        } \
    } while(0);

#define arrayUtility_checkEachDescending(array, count, check, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = _count - 1; i >= 0 ; i-- ) { \
            if (check) { \
                expression; \
            } \
        } \
    } while(0);

#define arrayUtility_checkBreakEach(array, count, check, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = 0; i < _count; i++ ) { \
            if (check) { \
                expression; \
                break; \
            } \
        } \
    } while(0);

#define arrayUtility_checkBreakEachDescending(array, count, check, expression) \
    do { \
        __typeof__ (count) _count = (count);\
        for ( size_t i = _count - 1; i >= 0 ; i-- ) { \
            if (check) { \
                expression; \
                break; \
            } \
        } \
    } while(0);

#endif //ARRAY_UTILITY_