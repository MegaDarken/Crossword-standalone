#include "charArrayTrio.h"

void charArrayTrio_createDest(struct charArrayTrio *dest, const int firstCount, const int secondCount, const int thirdCount)
{
    dest->first = charArray_create(firstCount);
    dest->second = charArray_create(secondCount);
    dest->third = charArray_create(thirdCount);
}

void charArrayTrio_createEmptyDest(struct charArrayTrio *dest)
{
    dest->first = charArray_create(0);
    dest->second = charArray_create(0);
    dest->third = charArray_create(0);
}

struct charArrayTrio charArrayTrio_create(const int firstCount, const int secondCount, const int thirdCount)
{
    struct charArrayTrio val = {};

    charArrayTrio_createDest(&val, firstCount, secondCount, thirdCount);

    return val;
}

struct charArrayTrio charArrayTrio_createEmpty()
{
    struct charArrayTrio val = {};

    charArrayTrio_createEmptyDest(&val);

    return val;
}

void charArrayTrio_free(struct charArrayTrio *var)
{
    charArray_free(&var->first);
    charArray_free(&var->second);
    charArray_free(&var->third);
}

void charArrayTrio_printAsChar(struct charArrayTrio *var)
{
    charArray_printAsChar(&var->first);
    putchar('|');
    charArray_printAsChar(&var->second);
    putchar('|');
    charArray_printAsChar(&var->third);
}
