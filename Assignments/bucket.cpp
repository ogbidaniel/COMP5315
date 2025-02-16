/*
*============================================================
*   Bucket Sort Algorithm (Using Raw Arrays & Integers)
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

// Maximum number of buckets
const int BUCKET_COUNT = 10;

// Function to perform Insertion Sort (for sorting elements inside each bucket)
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n, int maxValue) {
    // Step 1: Create buckets (each bucket has a max of `n` elements initially)
    int buckets[BUCKET_COUNT][n]; 
    int bucketSizes[BUCKET_COUNT] = {0}; // Track sizes of each bucket

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * BUCKET_COUNT) / (maxValue + 1); // Compute bucket index
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Add element to bucket
    }

    // Step 3: Sort each bucket using Insertion Sort
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Step 4: Concatenate all sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
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
    cout << "Bucket Sort Implementation (Using Raw Arrays & Integers)\n";

    int size = 15;
    int arr[size];

    // Define range of random numbers
    int min = 0, max = 99; // Increased range for variety

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
    cout << "Sorting with Bucket Sort!" << endl;
    bucketSort(arr, size, max);

    // Print sorted array
    printArray(arr, size);

    return 0;
}
