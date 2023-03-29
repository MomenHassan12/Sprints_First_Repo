#include "LCS.h"



/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS) {
    // Check for empty array
    if (arraySize == 0 ) {
        return -1;
    }

    // Check for invalid array size
    if ( arraySize > 10) {
        return -2;
    }

    // Sort the array using insertion sort
    int8_t sortResult = insertionSort(array, arraySize);
    if (sortResult != 0) {
        return sortResult;
    }

    // Find the length of the longest consecutive subsequence
    uint8_t maxLength = 1;
    uint8_t currentLength = 1;
    for (uint8_t i = 1; i < arraySize; i++) {
        if (array[i] == array[i-1] + 1) {
            currentLength++;
        } else if (array[i] == array[i-1]) {
            // Do nothing
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    // If no consecutive subsequence found, return -3
    if (maxLength == 1) {
        return -3;
    }

    // Return the length of the LCS
    *sizeofLCS = maxLength;
    return 0;
}
