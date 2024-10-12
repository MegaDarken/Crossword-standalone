#include "insertionSort.h"

#include "swapping.h"

void insertionSort_ascending(void* array, const size_t count, const size_t elementSize, void* firstElementComparisonPtr)
{
    size_t relative = firstElementComparisonPtr - array;

    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = i * elementSize; j > 0 && *(long*)(array + relative + (j - elementSize)) > *(long*)(array + relative + j); j -= elementSize)
        {
            swap((array + j - elementSize), (array + j), elementSize);
        }
        
    }
}

void insertionSort_descending(void* array, const size_t count, const size_t elementSize, void* firstElementComparisonPtr)
{
    size_t relative = firstElementComparisonPtr - array;

    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = i * elementSize; j > 0 && *(long*)(array + relative + (j - elementSize)) < *(long*)(array + relative + j); j -= elementSize)
        {
            swap((array + j - elementSize), (array + j), elementSize);
        }
        
    }
}