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

// Function to create a max heap using bottom-up heap construction
void HeapBottomUp(int H[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int k = i, v = H[k];
        bool heap = false;

        while (!heap && (2 * k + 1) < n) {  // Ensure k has at least one child
            int j = 2 * k + 1;  // Left child
            if (j + 1 < n && H[j] < H[j + 1]) {  // If right child exists and is greater
                j = j + 1;
            }

            if (v >= H[j]) {
                heap = true;
            } else {
                H[k] = H[j];  // Move larger child up
                k = j;  // Move down in the heap
            }
        }
        H[k] = v;  // Place v in final position
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build the max heap
    HeapBottomUp(arr, n);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move max element to end
        HeapBottomUp(arr, i);  // Rebuild the heap for remaining elements
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