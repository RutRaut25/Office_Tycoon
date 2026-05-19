//Write a program that handles runtime errors such as division by zero and invalid array
//index access using built-in exception handling mechanisms. In addition, define and
//implement custom exception classes to manage application-specific errors such as
//invalid input values or operation limits, ensuring clear error messages and safe
//program execution.

#include <iostream>
using namespace std;

// Custom Exception for Invalid Input
class InvalidInputException {
public:
    void message() {
        cout << "Error: Invalid input value!" << endl;
    }
};

// Custom Exception for Limit Exceeded
class LimitExceededException {
public:
    void message() {
        cout << "Error: Operation limit exceeded!" << endl;
    }
};

int main() {
    int a, b;

    // Division Exception
    try {
        cout << "Enter two numbers: ";
        cin >> a >> b;

        if (b == 0)
            throw b;

        cout << "Division Result: " << a / b << endl;
    }
    catch (int) {
        cout << "Error: Division by zero!" << endl;
    }

    // Array Index Exception
    try {
        int arr[5] = {1, 2, 3, 4, 5};
        int index;

        cout << "\nEnter array index (0-4): ";
        cin >> index;

        if (index < 0 || index >= 5)
            throw index;

        cout << "Element: " << arr[index] << endl;
    }
    catch (int) {
        cout << "Error: Invalid array index!" << endl;
    }

    // Custom Exception - Invalid Input
    try {
        int num;
        cout << "\nEnter a positive number: ";
        cin >> num;

        if (num < 0)
            throw InvalidInputException();

        cout << "Valid input: " << num << endl;
    }
    catch (InvalidInputException e) {
        e.message();
    }

    // Custom Exception - Limit Exceeded
    try {
        int value;
        cout << "\nEnter value (max 100): ";
        cin >> value;

        if (value > 100)
            throw LimitExceededException();

        cout << "Value accepted: " << value << endl;
    }
    catch (LimitExceededException e) {
        e.message();
    }

    return 0;
}