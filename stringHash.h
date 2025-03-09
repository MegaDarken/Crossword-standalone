#ifndef __STRING_HASH__
#define __STRING_HASH__

#include <stdlib.h>

#include "stringConstexpr.h"

//Constant(s)
#define CHAR_ARRAY_PRIME_A 777767777ul
#define CHAR_ARRAY_PRIME_B 322222223ul
#define CHAR_ARRAY_PRIME_C 6661111ul
#define CHAR_ARRAY_PRIME_D 841069ul

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#define stringHash_helper(_1, _2, NAME, ...) NAME

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
__UINT64_TYPE__ stringHash_size(const char *string, size_t stringSize)
{
    size_t hash = CHAR_ARRAY_PRIME_D;

    for (size_t i = 0; i < stringSize; i++)
    {
        hash = (hash * CHAR_ARRAY_PRIME_A) + (string[i] * (i & 1 ? CHAR_ARRAY_PRIME_B : CHAR_ARRAY_PRIME_C));
    }

    return hash;
}

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
__UINT64_TYPE__ stringHash_nullTerminated(const char* string)
{
    return stringHash_size(string, stringConstexpr_length(string));
}

#define stringHash(...) stringHash_helper(__VA_ARGS__, stringHash_size, stringHash_nullTerminated)(__VA_ARGS__)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__STRING_HASH__