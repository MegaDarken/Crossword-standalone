#ifndef __STRING_CONSTEXPR__
#define __STRING_CONSTEXPR__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef __cplusplus
constexpr
#endif //__cplusplus
size_t stringConstexpr_length(const char* string);

#define stringMacro_length(string) \
    ({ const char* _string = string; \
    const char* _character = _string; \
    for (; *_character; ++_character); \
    (_character - _string); })

#ifdef __cplusplus
constexpr
#endif //__cplusplus
size_t stringConstexpr_match(const char* string, const char match);

#define stringMacro_match(string, match) \
    ({ const char* _string = string; \
    const char _match = match; \
    const char* _character = _string; \
    for (; *_character == _match; ++_character); \
    (_character - _string); })

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__STRING_CONSTEXPR__
