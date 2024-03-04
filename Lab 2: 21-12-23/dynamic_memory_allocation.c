#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1;
    int size1 = 5;
    arr1 = (int*)malloc(size1 * sizeof(int));
    int i;
    
    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Using malloc:\n");
    for (i = 0; i < size1; i++) {
        arr1[i] = i;
        printf("%d ", arr1[i]);
    }
    printf("\n");
    free(arr1);

    int size2 = 5;
    int *arr2;

    arr2 = (int*)calloc(size2, sizeof(int));
    
    if (arr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nUsing calloc:\n");
    for (i = 0; i < size2; i++) {
        arr2[i] = i * 3;
        printf("%d ", arr2[i]);
    }
    printf("\n");


    int new_size = 10;
    arr2 = (int*)realloc(arr2, new_size * sizeof(int));
    
    if (arr2 == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("\nUsing realloc:\n");
    for (i = 0; i < new_size; i++) {
        arr2[i] = i * 4;
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr2);

    return 0;
}
