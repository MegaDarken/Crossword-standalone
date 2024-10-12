#ifndef CHAR_ARRAY_
#define CHAR_ARRAY_

#include <stdlib.h>
#include <stdio.h>

struct charArray
{
    size_t count;
    size_t size;
    char *array;
};

void charArray_createDest(struct charArray *dest);
void charArray_createDestWithInitialValue(struct charArray *dest, const char initialValue);
struct charArray charArray_createWithInitialValue(const size_t count, const char initialValue);
struct charArray charArray_create(const size_t count);

void charArray_setAll(struct charArray *var, const char value);
void charArray_set(struct charArray *var, char *array, const size_t count);

void charArray_resize(struct charArray *var, const size_t count);
void charArray_free(struct charArray *var);

int charArray_equals(struct charArray *first, struct charArray *second);
size_t charArray_hash(struct charArray *var);

size_t charArray_indicesOfValue(struct charArray *var, size_t *buffer, const size_t bufferCount, const char value);

void charArray_tolower(struct charArray *var);
void charArray_toupper(struct charArray *var);

void charArray_write(FILE* filePointer, struct charArray *var);
void charArray_readDest(FILE* filePointer, struct charArray *var);
struct charArray charArray_read(FILE* filePointer);

void charArray_print(struct charArray *var);
void charArray_printAsChar(struct charArray *var);
void charArray_printAsVolume(struct charArray *var);

#endif //CHAR_ARRAY_
