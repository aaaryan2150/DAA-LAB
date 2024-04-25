#include <stdio.h>



int binarySearch(int arr[], int left, int right, int key) {

    while (left <= right) {

        int mid = left + (right - left) / 2;

        // Check if key is present at mid

        if (arr[mid] == key) {

            return mid;

        }

        // If key is greater, ignore left half

        if (arr[mid] < key) {

            left = mid + 1;

        }

        // If key is smaller, ignore right half

        else {

            right = mid - 1;

        }

    }

    // If key is not present in array

    return -1;

}



int main() {

    int arr[] = {10, 20, 30, 40, 50, 60};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 40;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {

        printf("Element %d found at index %d\n", key, result);

    } else {

        printf("Element %d not found\n", key);

    }

    return 0;

}

