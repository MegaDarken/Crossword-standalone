#include "charGrid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "charArray.h"

void charGrid_createDest(struct charGrid *dest)
{
    dest->array = charArray_create(dest->width * dest->height);
}

void charGrid_createDestFromDimentions(const int width, const int height, struct charGrid *dest)
{
    dest->width = width;
    dest->height = height;

    charGrid_createDest(dest);
}

struct charGrid charGrid_create(const int width, const int height)
{
    struct charGrid val = { .width = width, .height = height };

    charGrid_createDest(&val);

    return val;
}

void charGrid_resize(struct charGrid *var, const int width, const int height)
{
    var->width = width;
    var->height = height;

    charArray_resize(&var->array, var->width * var->height);
}

void charGrid_free(struct charGrid *var)
{
    var->width = 0;
    var->height = 0;

    charArray_free(&var->array);
}

size_t charGrid_index(struct charGrid *var, const int x, const int y)
{
    return (y * var->width) + x;
}

char charGrid_get(struct charGrid *var, const int x, const int y)
{
    int index = charGrid_index(var, x, y);
    
    if (index >= var->array.count)
    {
        perror("Error index outside of grid array bounds!");
        abort();
    }

    return var->array.array[index];
}

void charGrid_set(struct charGrid *var, const int x, const int y, char value)
{
    int index = charGrid_index(var, x, y);
    
    if (index >= var->array.count)
    {
        perror("Error index outside of grid array bounds!");
        abort();
    }

    var->array.array[index] = value;
}

char charGrid_indexLeftColumn(struct charGrid *var, const size_t index)
{
    return index % var->width == 0;
}

char charGrid_indexRightColumn(struct charGrid *var, const size_t index)
{
    return index % var->width == var->width - 1;
}

char charGrid_indexTopRow(struct charGrid *var, const size_t index)
{
    return index < var->width;
}

char charGrid_indexBottomRow(struct charGrid *var, const size_t index)
{
    return index >= var->array.count - var->width;
}

void charGrid_setHorizontal_array(struct charGrid *var, const int x, const int y, char *array, size_t arrayCount)
{
    int index = charGrid_index(var, x, y);

    for (size_t i = 0; i < arrayCount && index < var->array.count; i++)
    {
        var->array.array[index] = array[i];
        index++;
    }
}

void charGrid_setVertical_array(struct charGrid *var, const int x, const int y, char *array, size_t arrayCount)
{
    int index = charGrid_index(var, x, y);

    for (size_t i = 0; i < arrayCount && index < var->array.count; i++)
    {
        var->array.array[index] = array[i];
        index += var->width;
    }
}

void charGrid_fprint(FILE *stream, struct charGrid *var)
{
    for (int i = 0; i < var->height; i++)
    {
        for (int j = 0; j < var->width; j++)
        {
            fprintf(stream, "%d ", charGrid_get(var, j, i));
        }

        fprintf(stream, "\n");
    }
}

void charGrid_print(struct charGrid *var)
{
    charGrid_fprint(stdout, var);
}

void charGrid_fprintAsChars(FILE *stream, struct charGrid *var)
{
    char* location = var->array.array;
    
    for (size_t i = 0; i < var->height; i++)
    {
        fprintf(stream, "%.*s\n", var->width, location);

        location += var->width;
    }
}

void charGrid_printAsChars(struct charGrid *var)
{
    charGrid_fprintAsChars(stdout, var);
}

void charGrid_fwprint(FILE *stream, struct charGrid *var)
{
    for (int i = 0; i < var->height; i++)
    {
        for (int j = 0; j < var->width; j++)
        {
            fwprintf(stream, L"%d ", charGrid_get(var, j, i));
        }

        fwprintf(stream, L"\n");
    }
}

void charGrid_wprint(struct charGrid *var)
{
    charGrid_fwprint(stdout, var);
}

void charGrid_fwprintAsChars(FILE *stream, struct charGrid *var)
{
    //char* location = var->array.array;
    
    for (size_t i = 0; i < var->height; i++)
    {
        for (size_t j = 0; j < var->width; j++)
        {
            fwprintf(stream, L"%c", charGrid_get(var, j, i));
        }

        //fwprintf(stream, L"%.*s\n", var->width, location);
        fwprintf(stream, L"\n");

        //location += var->width;
    }
}

void charGrid_wprintAsChars(struct charGrid *var)
{
    charGrid_fwprintAsChars(stdout, var);
}

// int main(int argc, char** argv)
// {
//     struct charGrid data = charGrid_create(10, 10);
//     struct charArray array = charArray_createWithInitialValue(10, 100);

//     charArray_printAsChar(&array);

//     printf("%d\n", data.width);
//     printf("%d\n", data.height);

//     charGrid_printAsVolume(&data);
// }
