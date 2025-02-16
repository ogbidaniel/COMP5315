/*
*============================================================
*   Sorting Algorithm Time Complexity Analysis
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================

*   Objective:
*   - Compare the execution time of different sorting algorithms on different input sizes.
*   - Run each algorithm **10 times** per array size and record the **average execution time**.
*   - Array sizes tested: **100, 1000, 10000, 100000**.
*   - Store the results in a format that can be exported to **Excel** for visualization.

*   Sorting Algorithms to Implement:
*   1. Selection Sort
*   2. Insertion Sort
*   3. Quick Sort
*   4. Heap Sort
*   5. Radix Sort
*   6. Bucket Sort
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

// Generate N random numbers
void generateRandomArray(int arr[], int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
}

// Print array
void printArray(int arr[], int size) {
    cout << "Array: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

//   SORTING ALGORITHMS

// SELECTION SORT
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
// INSERTION SORT
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        // insert arr[i] into the sorted subarray arr[1:i-1]
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// MERGE SORT
// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2]; // create temp arrays
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // Merge the two arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy any remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}
// QUICK SORT
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
// HEAP SORT
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
// RADIX SORT
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
// BUCKET SORT
const int BUCKET_COUNT = 10;// Maximum number of buckets
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
int main() {
    cout << "Algorithm Performance Profiler\n";
    // Declare array of size [100], [1000], [10000] and [100000]
    int size = {100}; // modify size to change size of array
    int arr[size];
    generateRandomArray(arr, size);
    printArray(arr, size);
    return 0;
}