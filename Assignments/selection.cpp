/*
*============================================================
*   Selection sort algorithm
*   Implemented in C++
*   Daniel Ogbuigwe
*   COMP5315 - Design and Analysis of Algorithms
*============================================================
*/

#include <iostream>
#include <random>
using namespace std;

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
    cout << "Selection Sort" << endl;
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
    cout << "Sorting with Selection Sort!" << endl;
    selectionSort(arr, size);

    // Print sorted array
    printArray(arr, size);

    return 0;
}