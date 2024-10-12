#include "stringHash.h"

#include <string.h>

//Constant(s)
#define CHAR_ARRAY_PRIME_A 524287
#define CHAR_ARRAY_PRIME_B 131071
#define CHAR_ARRAY_PRIME_C 40487
#define CHAR_ARRAY_PRIME_D 331999

//Method(s)
size_t stringHash_size(const char* string, const size_t stringSize)
{
    size_t output = CHAR_ARRAY_PRIME_D;

    for (size_t i = 0; i < stringSize; i++)
    {
        output = (output * CHAR_ARRAY_PRIME_A) + (string[i] * (i & 1 ? CHAR_ARRAY_PRIME_B : CHAR_ARRAY_PRIME_C));
    }

    return output;
}

size_t stringHash_nullTerminated(const char* string)
{
    stringHash_size(string, strlen(string));
}
