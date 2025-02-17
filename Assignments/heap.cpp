/*
*============================================================
*   Heap Sort Algorithm (Bottom-Up Construction)
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;       // Root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// build max heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n) {
    // Step 1: Build the max heap in O(n)
    buildMaxHeap(arr, n);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);    // Heapify the reduced heap
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
    cout << "Heap Sort Implementation\n";

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
    cout << "Sorting with Heap Sort!" << endl;
    heapSort(arr, size);

    // Print sorted array
    printArray(arr, size);

    return 0;
}