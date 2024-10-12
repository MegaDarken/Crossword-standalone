//Imports
#include "charArraySplit.h"

#include <string.h>
#include "arrayUtility.h"

//Methods
void charArraySplit_array_before(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index)
{
    size_t firstCount = index;
    size_t secondCount = inputCount - index;

    charArray_resize(first, firstCount);
    charArray_resize(second, secondCount);

    memcpy(first->array, inputArray, first->size);
    memcpy(second->array, inputArray + index, second->size);
}

void charArraySplit_before(struct charArray *input, struct charArray *first, struct charArray *second, size_t index)
{
    charArraySplit_array_before(input->array, input->count, first, second, index);
}

void charArraySplit_array_after(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index)
{
    size_t firstCount = index + 1;
    size_t secondCount = inputCount - index - 1;

    charArray_resize(first, firstCount);
    charArray_resize(second, secondCount);

    memcpy(first->array, inputArray, first->size);
    memcpy(second->array, inputArray + index + 1, second->size);
}

void charArraySplit_after(struct charArray *input, struct charArray *first, struct charArray *second, size_t index)
{
    charArraySplit_array_after(input->array, input->count, first, second, index);
}

void charArraySplit_array_on(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, size_t index)
{
    size_t firstCount = index;
    size_t secondCount = inputCount - index - 1;

    charArray_resize(first, firstCount);
    charArray_resize(second, secondCount);

    memcpy(first->array, inputArray, first->size);
    memcpy(second->array, inputArray + index + 1, second->size);
}

void charArraySplit_on(struct charArray *input, struct charArray *first, struct charArray *second, size_t index)
{
    charArraySplit_array_on(input->array, input->count, first, second, index);
}

size_t charArraySplit_array_onFirstValue(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, char value)
{
    size_t index = arrayUtility_indexOfFirst(inputArray, inputCount, value);

    charArraySplit_array_on(inputArray, inputCount, first, second, index);

    return index;
}

size_t charArraySplit_onFirstValue(struct charArray *input, struct charArray *first, struct charArray *second, char value)
{
    size_t index = arrayUtility_indexOfFirst(input->array, input->count, value);

    charArraySplit_on(input, first, second, index);

    return index;
}

size_t charArraySplit_array_onLastValue(const char *inputArray, const size_t inputCount, struct charArray *first, struct charArray *second, char value)
{
    size_t index = arrayUtility_indexOfFirst(inputArray, inputCount, value);

    charArraySplit_array_on(inputArray, inputCount, first, second, index);

    return index;
}

size_t charArraySplit_onLastValue(struct charArray *input, struct charArray *first, struct charArray *second, char value)
{
    size_t index = arrayUtility_indexOfFirst(input->array, input->count, value);

    charArraySplit_on(input, first, second, index);

    return index;
}