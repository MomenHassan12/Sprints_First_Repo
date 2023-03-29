#include "main.h"
int main() {
    int32_t array[arrsize];
    uint8_t arraySize;
    uint8_t sizeofLCS;

    // Test Case 1
    printf("Test Case 1:\n");
    printf("Enter 10 elements: ");
    for (uint8_t i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    int8_t result = lcsGetSize(array, 10, &sizeofLCS);
    if (result == 0) {
        printf("Longest consecutive subsequence size: %d\n", sizeofLCS);
    } else {
        printf("Error: %d\n", result);
    }

    // Test Case 2
    printf("\nTest Case 2:\n");
    printf("Enter 0 elements:\n ");
    result = lcsGetSize(array, 0, &sizeofLCS);
    if (result == -1) {
        printf("Array  is empty: %\n");
    } else if(result == 0) {
        printf("Longest consecutive subsequence size: %d\n", sizeofLCS);
    }else
    {
    printf("Error: %d\n", result);
    }
    // Test Case 3
    printf("\nTest Case 3:\n");
    printf("Enter 12 elements: ");
    for (uint8_t i = 0; i < 12; i++) {
        scanf("%d", &array[i]);
    }
    result = lcsGetSize(array, 12, &sizeofLCS);
    if (result == -2) {
        printf("Array size is invalid: %d\n", 12);
    } else if(result == 0) {
        printf("Longest consecutive subsequence size: %d\n", sizeofLCS);
    }else
    {
    printf("Error: %d\n", result);
    }
    // Test Case 4
    printf("\nTest Case 4:\n");
    printf("Enter 10 elements: ");
    for (uint8_t i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    result = lcsGetSize(array, 10, &sizeofLCS);
    if (result == 0) {
        printf("Longest consecutive subsequence size: %d\n", sizeofLCS);
    } else {
        printf("Error: %d\n", result);
    }

    // Test Case 5
    printf("\nTest Case 5:\n");
    printf("Enter 10 elements: ");
    for (uint8_t i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    result = lcsGetSize(array, 10, &sizeofLCS);
    if (result == -2) {
        printf("Array size is invalid: %d\n", 12);
    } else if(result == 0) {
        printf("Longest consecutive subsequence size: %d\n", sizeofLCS);
    }else if(result==-3)
    {
        printf("There is no  Longest consecutive subsequence\n");
    }
    else
    {
    printf("Error: %d\n", result);
    }

    return 0;
}

