/*
*============================================================
*   Radix Sort Algorithm (Uses Counting Sort)
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

// Function to perform Counting Sort on a specific digit
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array for digits (0-9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10; // Extract the digit at position exp
        count[digit]++;
    }

    // Modify count[i] to store the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in correct order
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    // Apply Counting Sort for each digit (starting from least significant)
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    cout << "Array: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "Radix Sort Implementation\n";

    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]);

    // Define range of random numbers
    int min = 1, max = 999; // Increased range for variety

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Assign random numbers to the array
    for (int i = 0; i < size; i++) {
        arr[i] = distrib(gen);
    }

    printArray(arr, size);

    // Sorting the array
    cout << "Sorting with Radix Sort!" << endl;
    radixSort(arr, size);

    // Print sorted array
    printArray(arr, size);

    return 0;
}