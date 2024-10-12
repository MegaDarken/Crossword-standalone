//Imports
#include "arrayList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Methods
void arrayList_createDest(struct arrayList *dest)
{
    dest->array = malloc( dest->elementSize * dest->count );

    if (!dest->array)
    {
        perror("Error allocating memory for array!");
        abort();
    }
}

struct arrayList arrayList_create(const size_t count, const size_t elementSize)
{
    struct arrayList val = { .count = count, .elementSize = elementSize };

    arrayList_createDest(&val);

    return val;
}

void arrayList_resize(struct arrayList *var, const size_t count)
{
    var->count = count;

    var->array = realloc(var->array, var->elementSize * count);

    if (!var->array)
    {
        perror("Error reallocating memory for array!");
        abort();
    }
}

void arrayList_free(struct arrayList *var)
{
    var->count = 0;

    free(var->array);
}

void *arrayList_get(struct arrayList *var, size_t index)
{
    return var->array + (index * var->elementSize);
}

void arrayList_set(struct arrayList *var, size_t index, void* value)
{
    memcpy(arrayList_get(var, index), value, var->elementSize);
}

void arrayList_append(struct arrayList *var, void* value)
{
    int originalCount = var->count;

    arrayList_resize(var, originalCount + 1);

    arrayList_set(var, originalCount, value);
}

void arrayList_remove(struct arrayList *var, const size_t index)
{
    size_t newCount = var->count - 1;

    for (size_t i = index; i < newCount; i++)
    {
        arrayList_set(var, i, arrayList_get(var, i+1));
    }

    arrayList_resize(var, newCount);
}

void arrayList_insert(struct arrayList *var, void* value, const size_t index)
{
    size_t originalCount = var->count;

    arrayList_resize(var, originalCount + 1);

    for (size_t i = originalCount; i > index; i--)
    {
        arrayList_set(var, i+1, arrayList_get(var, i));
    }

    arrayList_set(var, originalCount, value);
}

size_t arrayList_firstIndex(struct arrayList *var, void* value)
{
    for (size_t i = 0; i < var->count; i++)
    {
        if(arrayList_get(var, i) == value)
        {
            return i;
        } 
    }

    return -1;
}

size_t arrayList_lastIndex(struct arrayList *var, void* value)
{
    for (size_t i = var->count - 1; i >= 0; i--)
    {
        if(arrayList_get(var, i) == value)
        {
            return i;
        } 
    }

    return -1;
}
