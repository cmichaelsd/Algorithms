#include <stdio.h>

/**
 * O(n)
 */
void printArray(int arr[], int arr_count) {
    for (int i = 0; i < arr_count; ++i) {
        printf("%d\n", arr[i]);
    }
}

/**
 * O(1)
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * O(n)
 * n = high
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    printf("Hit\n");
    for (int j = low; j < high; ++j) {
        /**
         * Could improve by adding a condition 
         * for work not to be done if i == j
         */
        if (arr[j] < pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);

    return i + 1;
}

/**
 * O(n * log(n))
 * Will run log(n) times where n = arrays size
 * and for each call to partition a linear operation happens
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// int main() {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int arr_count = sizeof(arr) / sizeof(int);

//     quickSort(arr, 0, arr_count - 1);
//     printArray(arr, arr_count);

//     return 0;
// }