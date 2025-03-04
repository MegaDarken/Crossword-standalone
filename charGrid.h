#ifndef CHAR_GRID_
#define CHAR_GRID_

#include "charArray.h"

struct charGrid
{
    int width;
    int height;
    struct charArray array;
};

void charGrid_createDest(struct charGrid *dest);
void charGrid_createDestFromDimentions(const int width, const int height, struct charGrid *dest);
struct charGrid charGrid_create(const int width, const int height);

void charGrid_resize(struct charGrid *var, const int width, const int height);
void charGrid_free(struct charGrid *var);

size_t charGrid_index(struct charGrid *var, const int x, const int y);

char charGrid_get(struct charGrid *var, const int x, const int y);
void charGrid_set(struct charGrid *var, const int x, const int y, char value);

char charGrid_indexLeftColumn(struct charGrid *var, const size_t index);
char charGrid_indexRightColumn(struct charGrid *var, const size_t index);
char charGrid_indexTopRow(struct charGrid *var, const size_t index);
char charGrid_indexBottomRow(struct charGrid *var, const size_t index);

void charGrid_setHorizontal_array(struct charGrid *var, const int x, const int y, char *array, size_t arrayCount);
void charGrid_setVertical_array(struct charGrid *var, const int x, const int y, char *array, size_t arrayCount);

void charGrid_fprint(FILE *stream, struct charGrid *var);
void charGrid_print(struct charGrid *var);
void charGrid_fprintAsChars(FILE *stream, struct charGrid *var);
void charGrid_printAsChars(struct charGrid *var);

void charGrid_fwprint(FILE *stream, struct charGrid *var);
void charGrid_wprint(struct charGrid *var);
void charGrid_fwprintAsChars(FILE *stream, struct charGrid *var);
void charGrid_wprintAsChars(struct charGrid *var);

#endif //CHAR_GRID_
