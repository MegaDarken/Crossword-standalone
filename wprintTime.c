#include "wprintTime.h"

#include <time.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_ymd(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fwprintf(stream, L"%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_ymd()
{
    fwprintTime_ymd(stdout);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_dmy(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fwprintf(stream, L"%02d/%02d/%d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_dmy()
{
    fwprintTime_dmy(stdout);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fwprintTime_mdy(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fwprintf(stream, L"%02d/%02d/%d %02d:%02d:%02d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void wprintTime_mdy()
{
    fwprintTime_dmy(stdout);
}
