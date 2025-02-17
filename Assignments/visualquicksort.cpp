#include <iostream>
#include <vector>
#include <iomanip> // for std::setw (optional, for nicer formatting)

using namespace std;

// Forward declaration of quicksort (so we can call it recursively)
void quickSort(vector<int>& arr, int left, int right, int depth = 0);

// A helper function to print the current array state with optional labels
void printArray(const vector<int>& arr, int pivotIndex = -1, int i = -1, int j = -1) {
    // pivotIndex, i, j are optional indices to highlight
    for (int idx = 0; idx < (int)arr.size(); idx++) {
        // If we want, we can highlight pivot, i, j
        if (idx == pivotIndex) {
            // Mark the pivot
            cout << "[" << arr[idx] << " (pivot)] ";
        } 
        else if (idx == i) {
            // Mark i
            cout << "[" << arr[idx] << " (i)] ";
        } 
        else if (idx == j) {
            // Mark j
            cout << "[" << arr[idx] << " (j)] ";
        } 
        else {
            // Normal print
            cout << arr[idx] << " ";
        }
    }
    cout << endl;
}

// Partition function using the **first element** (arr[left]) as pivot (Hoare-like partition).
int partition(vector<int>& arr, int left, int right, int depth) {
    int pivotValue = arr[left];     // pivot is the first element in the current segment
    int i = left + 1;               // start i immediately to the right of pivot
    int j = right;                  // start j at the far right

    // Print initial state for this partition
    cout << string(depth, ' ') << "Partition: left=" << left 
         << ", right=" << right << ", pivot=" << pivotValue << endl;
    printArray(arr, left, i, j);

    while (true) {
        // Move i right while arr[i] <= pivotValue
        while (i <= j && arr[i] <= pivotValue) {
            i++;
        }
        // Move j left while arr[j] > pivotValue
        while (j >= i && arr[j] > pivotValue) {
            j--;
        }

        if (i >= j) {
            // We've crossed; partition loop is done
            break;
        }

        // Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
        cout << string(depth, ' ') << "  Swapped arr[" << i << "]=" << arr[i] 
             << " and arr[" << j << "]=" << arr[j] << endl;
        printArray(arr, left, i, j);

        // Move inward
        i++;
        j--;
    }

    // Finally, swap pivot (arr[left]) with arr[j] so pivot sits in its correct position
    swap(arr[left], arr[j]);
    cout << string(depth, ' ') << "  Pivot swap: placing pivot " << pivotValue 
         << " at index " << j << endl;
    printArray(arr, j); // highlight the pivot's new position

    // Return the pivot's final position
    return j;
}

// The main Quick Sort recursive function
void quickSort(vector<int>& arr, int left, int right, int depth) {
    // If the subarray has 1 or fewer elements, it's already sorted
    if (left >= right) return;

    // Partition the subarray around the pivot (arr[left])
    int pivotIndex = partition(arr, left, right, depth);

    // Recursively quicksort elements before the pivot
    quickSort(arr, left, pivotIndex - 1, depth + 2);

    // Recursively quicksort elements after the pivot
    quickSort(arr, pivotIndex + 1, right, depth + 2);
}

int main() {
    vector<int> arr = {9, 13, 20, 4, 50, 8, 18, 5};

    cout << "Initial array:" << endl;
    printArray(arr);
    cout << "\n--- Start Quick Sort (First Element as Pivot) ---\n" << endl;

    quickSort(arr, 0, (int)arr.size() - 1);

    cout << "\n--- Quick Sort Finished ---" << endl;
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}