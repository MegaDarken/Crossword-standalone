#ifndef __STRING_CONSTEXPR__
#define __STRING_CONSTEXPR__

#include <stddef.h>

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
size_t stringConstexpr_length(const char* string)
{
    const char* character = 0;
    for (character = string; *character; ++character);
    return(character - string);
}

#endif //__STRING_CONSTEXPR__
