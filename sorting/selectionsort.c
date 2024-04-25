#include <stdio.h>



void selectionSort(int arr[], int n) {

    int i, j, minIndex, temp;

    // Iterate through the array

    for (i = 0; i < n - 1; i++) {

        // Find the index of the minimum element in the unsorted part

        minIndex = i;

        for (j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {

                minIndex = j;

            }

        }

        // Swap the minimum element with the first element of the unsorted part

        temp = arr[minIndex];

        arr[minIndex] = arr[i];

        arr[i] = temp;

    }

}



int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");

    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");



    selectionSort(arr, n);



    printf("Sorted array: \n");

    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

    return 0;

}
