#ifndef __STRING_HASH__
#define __STRING_HASH__

#include <stdlib.h>

#define stringHash_helper(_1, _2, NAME, ...) NAME

size_t stringHash_size(const char* string, const size_t stringSize);
size_t stringHash_nullTerminated(const char* string);

#define stringHash(...) stringHash_helper(__VA_ARGS__, stringHash_size, stringHash_nullTerminated)(__VA_ARGS__)

#endif //__STRING_HASH__