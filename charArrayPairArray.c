#include "charArrayPairArray.h"

#include "charArrayPair.h"
#include "swapping.h"
#include "randomTable.h"

void charArrayPairArray_free(void *array, const size_t count)
{
    struct charArrayPair *structArray = array;

    for (size_t i = 0; i < count; i++)
    {
        charArrayPair_free((struct charArrayPair *)&structArray[i]);
    }
}

void charArrayPairArray_swap(void *array, const size_t count, const size_t firstIndex, const size_t secondIndex)
{
    if (firstIndex == secondIndex) return;
    //struct charArrayPair *structArray = array;
    swap(array + (firstIndex * sizeof(struct charArrayPair)), array + (secondIndex * sizeof(struct charArrayPair)), sizeof(struct charArrayPair));
}

void charArrayPairArray_quicksort_firstLengthAccending(void *array, const size_t count)
{
    if (count <= 1)
    {
        return;
    }

    struct charArrayPair *structArray = array;

    size_t pivotIndex = count - 1;
    size_t pivotFirstLength = (structArray[pivotIndex].first.count);

    size_t lowerIndex = 0;
    size_t higherIndex = count - 1;

    for (size_t i = 0; i < count - 1; i++)
    {
        if ((structArray[i]).first.count < pivotFirstLength)
        {
            swap(&structArray[lowerIndex], &structArray[i]);
            lowerIndex++;
        }
    }
    
    swap(&structArray[lowerIndex], &structArray[pivotIndex]);

    charArrayPairArray_quicksort_firstLengthAccending(array, lowerIndex);
    charArrayPairArray_quicksort_firstLengthAccending(array + lowerIndex + 1, count - (lowerIndex + 1));
}

void charArrayPairArray_printAsChar(void *array, const size_t count)
{
    struct charArrayPair *structArray = array;

    for (size_t i = 0; i < count; i++)
    {
        charArrayPair_printAsChar(&structArray[i]);
        printf("\n");
    }
    
}
