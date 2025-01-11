#ifndef LOOP_UTILITY_
#define LOOP_UTILITY_

#define loop_each(count, expression) \
    for ( size_t i = 0; i < count; i++ ) { \
        expression; \
    }

#define loop_eachDescending(count, expression) \
    for ( size_t i = count - 1; i >= 0 ; i-- ) { \
        expression; \
    }

#define loop_checkEach(count, check, expression) \
    for ( size_t i = 0; i < count; i++ ) { \
        if (check) { \
            expression; \
        } \
    }

#define loop_checkEachDescending(count, check, expression) \
    for ( size_t i = count - 1; i >= 0 ; i-- ) { \
        if (check) { \
            expression; \
        } \
    }

#define loop_checkBreakEach(count, check, expression) \
    for ( size_t i = 0; i < count; i++ ) { \
        if (check) { \
            expression; \
            break; \
        } \
    }

#define loop_checkBreakEachDescending(count, check, expression) \
    for ( size_t i = count - 1; i >= 0 ; i-- ) { \
        if (check) { \
            expression; \
            break; \
        } \
    } \

#endif //LOOP_UTILITY_