/*
*============================================================
*   Quick Sort algorithm (Hoare Partition)
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

// Hoare Partition function
int HoarePartition(int arr[], int left, int right) {
    int pivot = arr[left];  // Choose the first element as pivot
    int i = left - 1, j = right + 1;

    while (true) {
        // Move right until we find an element >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Move left until we find an element <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers have crossed, return j as partition index
        if (i >= j)
            return j;

        // Swap out-of-place elements
        swap(arr[i], arr[j]);
    }
}

// QuickSort function using Hoare Partition
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int s = HoarePartition(arr, left, right);
        quickSort(arr, left, s);     // Sort left partition
        quickSort(arr, s + 1, right); // Sort right partition
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
    cout << "Quick Sort Implementation\n";

    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]);

    // Define range of random numbers
    int min = 1, max = 100;

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
    cout << "Sorting with Quick Sort!" << endl;
    quickSort(arr, 0, size - 1);

    // Print sorted array
    printArray(arr, size);

    return 0;
}