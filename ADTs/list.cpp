// Abstract Data Type: List
// A list is a finite sequence of data items in a certain linear order.
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// 1. Define a struct for the List:
//    - Include an array to store elements.
//    - Include an integer to track the current size.
//    - Define a constant for the maximum allowed size.
//    - Ensure the struct has a semicolon at the end.
struct List
{
    int data[MAX_SIZE];
    int currSize;
};

// 2. Implement a function to initialize the list:
//    - Take a reference to a List object as a parameter.
//    - Set the size to 0.
void initList(List& lst)
{
    lst.currSize = 0;
}

// 3. Implement a function to add an element to the front:
//    - Take a reference to a List object as a parameter.
//    - Check if the list is full before inserting.
//    - Shift all existing elements to the right.
//    - Insert the new element at index 0.
//    - Increment the size.
void addFront(List& lst, int newElement)
{
    if (lst.currSize >= MAX_SIZE)
    {
        cout << "List is full.\n";
        return;
    }

    // Shift elements to the right
    for (int i = lst.currSize; i > 0; i--)
    {
        lst.data[i] = lst.data[i - 1];
    }

    // Insert new element at the front
    lst.data[0] = newElement;
    lst.currSize++;
}

// 4. Implement a function to get the first element:
//    - Check if the list is empty.
//    - Return the first element.
int getFirst(const List& lst)
{
    if (lst.currSize == 0)
    {
        cout << "List is empty.\n";
        return -1; // Return an invalid value indicating error
    }
    return lst.data[0];
}

// 5. Implement a function to get the rest of the list:
//    - Create a new list.
//    - Copy all elements except the first one into the new list.
//    - Return the new list.
List getRest(const List& lst)
{
    List restList;
    restList.currSize = lst.currSize - 1;

    for (int i = 1; i < lst.currSize; i++)
    {
        restList.data[i - 1] = lst.data[i];
    }

    return restList;
}

// 6. Implement a function to check if the list is empty:
//    - Return true if the size is 0, otherwise return false.
bool isEmpty(const List& lst)
{
    return lst.currSize == 0;
}

// 7. Implement a function to print the list:
//    - Loop through the array and print each element.
void printList(const List& lst)
{
    if (lst.currSize == 0)
    {
        cout << "List is empty.\n";
        return;
    }

    for (int i = 0; i < lst.currSize; i++)
    {
        cout << lst.data[i] << " ";
    }
    cout << endl;
}

// 8. Implement a main function to:
//    - Create and initialize a list.
//    - Add elements to the list.
//    - Print the list.
//    - Get and print the first element.
//    - Get and print the rest of the list.
int main()
{
    List myList;
    initList(myList);

    addFront(myList, 10);
    addFront(myList, 20);
    addFront(myList, 30);

    cout << "List elements: ";
    printList(myList);

    cout << "First element: " << getFirst(myList) << endl;

    List rest = getRest(myList);
    cout << "Rest of the list: ";
    printList(rest);

    return 0;
}