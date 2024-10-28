#include "printTime.h"

#include <time.h>

void fprintTime_Bigendian(FILE *stream)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(stream, "%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void printTime_Bigendian()
{
    fprintTime_Bigendian(stdout);
}