
#include "stringConstexpr.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef __cplusplus
constexpr
#endif //__cplusplus
size_t stringConstexpr_length(const char* string)
{
    const char* character = string;
    for (; *character; ++character);
    return(character - string);
}

#ifdef __cplusplus
constexpr
#endif //__cplusplus
size_t stringConstexpr_match(const char* string, const char match)
{
    const char* character = string;
    for (; *character == match; ++character);
    return(character - string);
}

#ifdef __cplusplus
}
#endif //__cplusplus