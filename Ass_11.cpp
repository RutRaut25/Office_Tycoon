//Write a program to create a Book class and extend it by using dynamic memory
//allocation. Use the new keyword and object pointers to create Book objects
//dynamically. The program should allow the user to:
//a) Input details of one or more books.
//b) Display the book details.
//c) Demonstrate the use of dynamic memory allocation for objects.

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    void input() {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: " << price << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    // Dynamic allocation of array of objects
    Book *b = new Book[n];

    // Input details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Book " << i + 1 << ":\n";
        b[i].input();
    }

    // Display details
    cout << "\n--- Book Details ---\n";
    for (int i = 0; i < n; i++) {
        b[i].display();
    }

    // Free memory
    delete[] b;

    return 0;