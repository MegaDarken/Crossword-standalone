#ifndef __STRING_HASH__
#define __STRING_HASH__

#include <stdlib.h>
#include <string.h>

//Constant(s)
#define CHAR_ARRAY_PRIME_A 524287
#define CHAR_ARRAY_PRIME_B 131071
#define CHAR_ARRAY_PRIME_C 40487
#define CHAR_ARRAY_PRIME_D 331999

#define stringHash_helper(_1, _2, NAME, ...) NAME

#define stringHash_size(string, stringSize) ({ \
    size_t _hash = CHAR_ARRAY_PRIME_D; \
    for (size_t i = 0; i < stringSize; i++) { \
        _hash = (_hash * CHAR_ARRAY_PRIME_A) + (string[i] * (i & 1 ? CHAR_ARRAY_PRIME_B : CHAR_ARRAY_PRIME_C)); \
    } \
    _hash; })

#define stringHash_nullTerminated(string) stringHash_size(string, strlen(string))

#define stringHash(...) stringHash_helper(__VA_ARGS__, stringHash_size, stringHash_nullTerminated)(__VA_ARGS__)

#endif //__STRING_HASH__