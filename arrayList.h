#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include <stdlib.h>

struct arrayList
{
    size_t count;
    size_t elementSize;
    void *array;
};

void arrayList_createDest(struct arrayList *dest);
struct arrayList arrayList_create(const size_t count, const size_t elementSize);

void arrayList_resize(struct arrayList *var, const size_t count);
void arrayList_free(struct arrayList *var);

void *arrayList_get(struct arrayList *var, size_t index);
void arrayList_set(struct arrayList *var, size_t index, void* value);

void arrayList_append(struct arrayList *var, void* value);
void arrayList_remove(struct arrayList *var, const size_t index);
void arrayList_insert(struct arrayList *var, void* value, const size_t index);

size_t arrayList_firstIndex(struct arrayList *var, void* value);
size_t arrayList_lastIndex(struct arrayList *var, void* value);

#endif //ARRAY_LIST_