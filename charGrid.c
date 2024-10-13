#include "charGrid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char charGrid_get(struct charGrid *var, int x, int y)
{
    int index = (y * var->width) + x;
    
    if (index >= var->array.count)
    {
        perror("Error index outside of grid array bounds!");
        abort();
    }

    return var->array.array[index];
}

void charGrid_set(struct charGrid *var, int x, int y, char value)
{
    int index = (y * var->width) + x;
    
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

void charGrid_setHorizontal_array(struct charGrid *var, int x, int y, char *array, size_t arrayCount)
{
    int index = (y * var->width) + x;

    for (size_t i = 0; i < arrayCount && index < var->array.count; i++)
    {
        var->array.array[index] = array[i];
        index++;
    }
}

void charGrid_setVertical_array(struct charGrid *var, int x, int y, char *array, size_t arrayCount)
{
    int index = (y * var->width) + x;

    for (size_t i = 0; i < arrayCount && index < var->array.count; i++)
    {
        var->array.array[index] = array[i];
        index += var->width;
    }
}

void charGrid_print(struct charGrid *var)
{
    for (int i = 0; i < var->height; i++)
    {
        for (int j = 0; j < var->width; j++)
        {
            printf("%d ", charGrid_get(var, j, i));
        }

        printf("\n");
    }
}

void charGrid_printAsChars(struct charGrid *var)
{
    char* location = var->array.array;
    
    for (size_t i = 0; i < var->height; i++)
    {
        printf("%.*s\n", var->width, location);

        location += var->width;
    }
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
