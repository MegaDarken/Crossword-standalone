#ifndef CHAR_ARRAY_TRIO_
#define CHAR_ARRAY_TRIO_

#include "charArray.h"

struct charArrayTrio
{
    struct charArray first;
    struct charArray second;
    struct charArray third;
};

void charArrayTrio_createDest(struct charArrayTrio *dest, const int firstCount, const int secondCount);
void charArrayTrio_createEmptyDest(struct charArrayTrio *dest);
struct charArrayTrio charArrayTrio_create(const int firstCount, const int secondCount);
struct charArrayTrio charArrayTrio_createEmpty();

void charArrayTrio_free(struct charArrayTrio *var);

void charArrayTrio_printAsChar(struct charArrayTrio *var);

#endif //CHAR_ARRAY_TRIO_