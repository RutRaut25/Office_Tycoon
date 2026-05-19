//Write a C++ program that implements a generic function template to sort an array
//of any data type using either Bubble Sort or Selection Sort.
//The program should:
//a) Accept an array of any type (such as int, float, char, etc.) from the user.
//b) Use the generic function template to sort the array.
//c) Display the sorted array.

#include <iostream>
#include <string>

using namespace std;

// Generic helper function to print an array of any type
template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Generic Template Function for Bubble Sort
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Generic Template Function for Selection Sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swapping with the minimum element found
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Helper template function to manage user input and sorting execution
template <typename T>
void handleArrayInputAndSort(int size) {
    T* arr = new T[size];
    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "\nChoose sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "Enter choice (1-2): ";
    int algoChoice;
    cin >> algoChoice;

    cout << "\nOriginal Array: ";
    printArray(arr, size);

    // b) Using the generic function template to sort the array
    if (algoChoice == 1) {
        bubbleSort(arr, size);
        cout << "Sorted using Bubble Sort." << endl;
    } else if (algoChoice == 2) {
        selectionSort(arr, size);
        cout << "Sorted using Selection Sort." << endl;
    } else {
        cout << "Invalid choice! Defaulting to Bubble Sort." << endl;
        bubbleSort(arr, size);
    }

    // c) Display the sorted array
    cout << "Sorted Array:   ";
    printArray(arr, size);

    delete[] arr; // Free dynamic memory
}

int main() {
    int dataTypeChoice;
    int size;

    cout << "Select Data Type for the Array:" << endl;
    cout << "1. Integer (int)" << endl;
    cout << "2. Floating-point (float)" << endl;
    cout << "3. Character (char)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> dataTypeChoice;

    // a) Accept array size and elements from the user
    cout << "Enter the number of elements in the array: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    switch (dataTypeChoice) {
        case 1:
            handleArrayInputAndSort<int>(size);
            break;
        case 2:
            handleArrayInputAndSort<float>(size);
            break;
        case 3:
            handleArrayInputAndSort<char>(size);
            break;
        default:
            cout << "Invalid data type selection!" << endl;
            break;
    }

    return 0;
}
