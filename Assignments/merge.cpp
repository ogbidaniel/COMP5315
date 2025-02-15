/*
*============================================================
*   Merge Sort algorithm
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
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

void printArray(int arr[], int size)
{
    cout << "Array: [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    cout << "Merge Sort" << endl;
    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]);
    // range of random numbers
    int min = 1, max = 60;

    // initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    
    // assign random numbers to the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = distrib(gen);
    }
    printArray(arr, size);

    // Sorting the array
    cout << "Sorting with Merge Sort!" << endl;
    mergeSort(arr, 0, size - 1);

    // Print sorted array
    printArray(arr, size);

    return 0;
}