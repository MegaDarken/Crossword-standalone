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

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_createDest(struct charArray *dest);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_createDestWithInitialValue(struct charArray *dest, const char initialValue);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_createWithInitialValue(const size_t count, const char initialValue);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_create(const size_t count);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_setAll(struct charArray *var, const char value);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_set(struct charArray *var, char *array, const size_t count);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_resize(struct charArray *var, const size_t count);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_free(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int charArray_equals(struct charArray *first, struct charArray *second);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t charArray_hash(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t charArray_indicesOfValue(struct charArray *var, size_t *buffer, const size_t bufferCount, const char value);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_tolower(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_toupper(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_write(FILE* filePointer, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_readDest(FILE* filePointer, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
struct charArray charArray_read(FILE* filePointer);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fprint(FILE *stream, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_print(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fprintAsChar(FILE *stream, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_printAsChar(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fwprint(FILE *stream, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_wprint(struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_fwprintAsChar(FILE *stream, struct charArray *var);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void charArray_wprintAsChar(struct charArray *var);

// #ifdef __cplusplus
// extern "C"
// #endif //__cplusplus
// void charArray_fprintAsVolume(FILE *stream, struct charArray *var);

// #ifdef __cplusplus
// extern "C"
// #endif //__cplusplus
// void charArray_printAsVolume(struct charArray *var);

#endif //CHAR_ARRAY_
