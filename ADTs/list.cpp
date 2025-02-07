// Abstract Data Type: List
// A list is a finite sequence of data items in a certain linear order.
#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 100;

// struct for the List:
struct List
{
    int data[MAX_SIZE];
    int currSize;
};

// initialize the list
void initList(List& lst)
{
    lst.currSize = 0;
}

// function to add an element to the front
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

// function to get the first element
int getFirst(const List& lst)
{
    if (lst.currSize == 0)
    {
        cout << "List is empty.\n";
        return -1; // Return an invalid value indicating error
    }
    return lst.data[0];
}

// function to get the rest of the list
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

// function to check if the list is empty
bool isEmpty(const List& lst)
{
    return lst.currSize == 0;
}

// function to print the list
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

int main()
{
    List myList;
    initList(myList);

    cout << "Enter numbers into the list (Press 'f' to stop):" << endl;
    int number;
    while (cin >> number)
    {
        addFront(myList, number);
    }
    cin.clear(); // Clear the error state of cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining input


    cout << "List elements: ";
    printList(myList);

    cout << "First element: " << getFirst(myList) << endl;

    List rest = getRest(myList);
    cout << "Rest of the list: ";
    printList(rest);

    return 0;
}