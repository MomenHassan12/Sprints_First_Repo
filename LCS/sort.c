#include "sort.h"
/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);
int8_t insertionSort(int32_t *array, uint8_t arraySize) {
                                             // Check for empty array
    if (arraySize == 0)
        {
        return -1;
        }
     if ( arraySize > 10) {
        return -2;
    }
int32_t temp;
    // Insertion sort algorithm
    for (int8_t i = 0; i < arraySize; i++) {
        for(int8_t j=i+1;j<arraySize;j++)
        {
            if(array[i]>array[j])
            {
             temp=array[i];
             array[i]=array[j];
             array[j]=temp;
            }

        }

    }

    // Sorting done without errors
    return 0;
}

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */

void printArray(int32_t *array, uint8_t arraySize) {
    for (uint8_t i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

