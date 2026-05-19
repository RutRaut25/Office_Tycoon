//Implement a generic C++ program using a C++ Standard Library collection class
//(such as vector or list) to count the number of elements in the collection that satisfy a
//specific property. Example properties include:
//Even numbers
//Odd numbers
//Prime numbers
//Palindromes
//The program should:
//a) Allow the user to input the elements of the collection.
//b) Allow the user to choose a property to count.
//c) Display the total count of elements satisfying the selected property

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Generic template function to count elements matching a predicate
template <typename T, typename Predicate>
int countMatchingElements(const vector<T>& collection, Predicate property) {
    return count_if(collection.begin(), collection.end(), property);
}

// Property 1: Check if a number is even
bool isEven(int n) {
    return n % 2 == 0;
}

// Property 2: Check if a number is odd
bool isOdd(int n) {
    return n % 2 != 0;
}

// Property 3: Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Property 4: Check if a number is a palindrome
bool isPalindrome(int n) {
    if (n < 0) return false; 
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    vector<int> numbers;
    int size, element, choice;

    // a) Allow the user to input the elements of the collection
    cout << "Enter the number of elements you want to add: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Invalid size entered." << endl;
        return 1;
    }

    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> element;
        numbers.push_back(element);
    }

    // b) Allow the user to choose a property to count
    cout << "\nChoose a property to count:" << endl;
    cout << "1. Even numbers" << endl;
    cout << "2. Odd numbers" << endl;
    cout << "3. Prime numbers" << endl;
    cout << "4. Palindromes" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    int totalCount = 0;

    // c) Display the total count of elements satisfying the selected property
    switch (choice) {
        case 1:
            totalCount = countMatchingElements(numbers, isEven);
            cout << "\nTotal count of Even numbers: " << totalCount << endl;
            break;
        case 2:
            totalCount = countMatchingElements(numbers, isOdd);
            cout << "\nTotal count of Odd numbers: " << totalCount << endl;
            break;
        case 3:
            totalCount = countMatchingElements(numbers, isPrime);
            cout << "\nTotal count of Prime numbers: " << totalCount << endl;
            break;
        case 4:
            totalCount = countMatchingElements(numbers, isPalindrome);
            cout << "\nTotal count of Palindromes: " << totalCount << endl;
            break;
        default:
            cout << "\nInvalid choice selected!" << endl;
            break;
    }

    return 0;
}
