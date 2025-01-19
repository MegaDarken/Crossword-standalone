#include "charArrayTrioArray.h"

#include "charArrayTrio.h"
#include "swapping.h"
#include "randomTable.h"

void charArrayTrioArray_free(void *array, const size_t count)
{
    struct charArrayTrio *structArray = array;

    for (size_t i = 0; i < count; i++)
    {
        charArrayTrio_free((struct charArrayTrio *)&structArray[i]);
    }
}

void charArrayTrioArray_swap(void *array, const size_t count, const size_t firstIndex, const size_t secondIndex)
{
    if (firstIndex == secondIndex) return;
    //struct charArrayTrio *structArray = array;
    swap(array + (firstIndex * sizeof(struct charArrayTrio)), array + (secondIndex * sizeof(struct charArrayTrio)), sizeof(struct charArrayTrio));
}

void charArrayTrioArray_quicksort_firstLengthAccending(void *array, const size_t count)
{
    if (count <= 1)
    {
        return;
    }

    struct charArrayTrio *structArray = array;

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

    charArrayTrioArray_quicksort_firstLengthAccending(array, lowerIndex);
    charArrayTrioArray_quicksort_firstLengthAccending(array + lowerIndex + 1, count - (lowerIndex + 1));
}

void charArrayTrioArray_printAsChar(void *array, const size_t count)
{
    struct charArrayTrio *structArray = array;

    for (size_t i = 0; i < count; i++)
    {
        charArrayTrio_printAsChar(&structArray[i]);
        printf("\n");
    }
    
}
