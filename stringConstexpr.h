#ifndef __STRING_CONSTEXPR__
#define __STRING_CONSTEXPR__

#include <stddef.h>

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
size_t stringConstexpr_length(const char* string)
{
    const char* character = string;
    for (; *character; ++character);
    return(character - string);
}

#ifdef __cplusplus
extern "C" constexpr
#endif //__cplusplus
size_t stringConstexpr_match(const char* string, const char match)
{
    const char* character = string;
    for (; *character == match; ++character);
    return(character - string);
}

#endif //__STRING_CONSTEXPR__
