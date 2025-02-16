/*
*============================================================
*   Insertion Sort algorithm
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        // insert arr[i] into the sorted subarray arr[1:i-1]
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    cout << "Insertion Sort" << endl;
    int arr[15];
    int size = sizeof(arr) / sizeof(arr[0]);
    // range of random numbers
    int min = 1, max = 100;

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
    cout << "Sorting with Insertion Sort!" << endl;
    insertionSort(arr, size);

    // Print sorted array
    printArray(arr, size);

    return 0;
}