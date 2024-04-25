#include <stdio.h>



// Function to perform Counting Sort

void countingSort(int arr[], int n, int range) {

    int count[range + 1]; // Create a count array to store the frequency of each element

    int output[n]; // Create an output array to store the sorted elements



    // Initialize count array with zeros

    for (int i = 0; i <= range; ++i) {

        count[i] = 0;

    }



    // Store the frequency of each element in count array

    for (int i = 0; i < n; ++i) {

        ++count[arr[i]];

    }



    // Modify count array to store the actual position of each element in output array

    for (int i = 1; i <= range; ++i) {

        count[i] += count[i - 1];

    }



    // Build the output array

    for (int i = n - 1; i >= 0; --i) {

        output[count[arr[i]] - 1] = arr[i];

        --count[arr[i]];

    }



    // Copy the sorted elements back to the original array

    for (int i = 0; i < n; ++i) {

        arr[i] = output[i];

    }

}



// Function to print an array

void printArray(int arr[], int n) {

    for (int i = 0; i < n; ++i) {

        printf("%d ", arr[i]);

    }

    printf("\n");

}



// Main function to test the Counting Sort algorithm

int main() {

    int arr[] = {4, 2, 2, 8, 3, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int range = 8; // Assuming the range of input values is known



    printf("Original array: ");

    printArray(arr, n);



    countingSort(arr, n, range);



    printf("Sorted array: ");

    printArray(arr, n);



    return 0;

}

