//Imports
#include "charArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayUtility.h"
#include "stringHash.h"

//Methods
#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_createDest(struct charArray *dest)
{
    dest->size = sizeof(char) * dest->count;

    dest->array = realloc(dest->array, dest->size);

    if (!dest->array)
    {
        perror("Error allocating memory for array!");
        abort();
    }
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_createDestWithInitialValue(struct charArray *dest, const char initialValue)
{
    charArray_createDest(dest);
    
    charArray_setAll(dest, initialValue);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_createWithInitialValue(const size_t count, const char initialValue)
{
    struct charArray val = { .count = count };

    charArray_createDestWithInitialValue(&val, initialValue);

    return val;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_create(const size_t count)
{
    struct charArray val = { .count = count };

    charArray_createDest(&val);

    return val;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_setAll(struct charArray *var, const char value)
{
    memset(var->array, value, var->size);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_set(struct charArray *var, char *array, const size_t count)
{
    charArray_resize(var, count);

    memcpy(var->array, array, count);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_resize(struct charArray *var, const size_t count)
{
    var->count = count;

    charArray_createDest(var);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_free(struct charArray *var)
{
    var->count = 0;
    var->size = 0;

    free(var->array);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int charArray_equals(struct charArray *first, struct charArray *second)
{
    if (first->count != second->count) return 0;
    if (first->size != second->size) return 0;

    for (size_t i = 0; i < first->count; i++)
    {
        if (first->array[i] != second->array[i]) return 0;
    }

    return 1;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t charArray_hash(struct charArray *var)
{
    return stringHash(var->array, var->size);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t charArray_indicesOfValue(struct charArray *var, size_t *buffer, const size_t bufferCount, const char value)
{
    size_t count = 0;

    for (size_t i = 0; i < var->count && count < bufferCount; i++)
    {
        if (var->array[i] == value)
        {
            buffer[count] = i;

            count++;
        }
    }
    
    return count;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_tolower(struct charArray *var)
{
    for (size_t i = 0; i < var->count; i++)
    {
        var->array[i] = tolower(var->array[i]);
    }
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_toupper(struct charArray *var)
{
    for (size_t i = 0; i < var->count; i++)
    {
        var->array[i] = toupper(var->array[i]);
    }
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_write(FILE* filePointer, struct charArray *var)
{
    size_t size = 0;
    size += fwrite(&var->count, sizeof(var->count), 1, filePointer);
    size += fwrite(&var->size, sizeof(var->size), 1, filePointer);
    size += fwrite(var->array, sizeof(var->array[0]), var->count, filePointer);
    if ( size != sizeof(struct charArray) ) printf("Mis-size from charArray fwrite");
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_readDest(FILE* filePointer, struct charArray *var)
{
    size_t size = 0;
    size += fread(&var->count, sizeof(var->count), 1, filePointer);
    size += fread(&var->size, sizeof(var->size), 1, filePointer);
    size += fread(var->array, sizeof(var->array[0]), var->count, filePointer);
    if ( size != sizeof(struct charArray) ) printf("Mis-size from charArray fread");
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_read(FILE* filePointer)
{
    struct charArray val = { };

    charArray_readDest(filePointer, &val);

    return val;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fprint(FILE *stream, struct charArray *var)
{
    for (size_t i = 0; i < var->count; i++)
    {
        fprintf(stream, "%d ", var->array[i]);
    }
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_print(struct charArray *var)
{
    charArray_fprint(stdout, var);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fprintAsChar(FILE *stream, struct charArray *var)
{
    fprintf(stream, "%.*s", (int)var->count, var->array);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_printAsChar(struct charArray *var)
{
    charArray_fprintAsChar(stdout, var);
}

//For testing
// int main(int argc, char** argv)
// {
//     struct charArray array = charArray_create(10);

//     charArray_print(&array);
//     printf("\n");

//     charArray_resize(&array, 15);

//     charArray_print(&array);
// }
