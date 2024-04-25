#include <stdio.h>



int linearSearch(int arr[], int n, int key) {

    for (int i = 0; i < n; i++) {

        if (arr[i] == key) {

            return i; // Return the index if key is found

        }

    }

    return -1; // Return -1 if key is not found

}



int main() {

    int arr[] = {12, 34, 45, 67, 89, 23};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 67;

    int index = linearSearch(arr, n, key);

    if (index != -1) {

        printf("Element %d found at index %d\n", key, index);

    } else {

        printf("Element %d not found\n", key);

    }

    return 0;

}

