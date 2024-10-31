#include "printTime.h"

#include <time.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_ymd(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(stream, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_ymd()
{
    fprintTime_ymd(stdout);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_dmy(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(stream, "%02d/%02d/%d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_dmy()
{
    fprintTime_dmy(stdout);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void fprintTime_mdy(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(stream, "%02d/%02d/%d %02d:%02d:%02d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void printTime_mdy()
{
    fprintTime_dmy(stdout);
}
