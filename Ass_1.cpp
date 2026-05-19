
//Write a C++ program to implement a class named Book with the following data
//members:
//Private: bookId, bookName, author, price
//Public: getDetails(), printDetails()
//The program should accept details of multiple books from the user, display the book
//information in tabular form, and calculate and display the total price of all the books.

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    // Private data members
    int bookId;
    string bookName;
    string author;
    double price;

public:
    // Simple function to get inputs
    void getDetails() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        
        cout << "Enter Book Name (No spaces): ";
        cin >> bookName;
        
        cout << "Enter Author Name (No spaces): ";
        cin >> author;
        
        cout << "Enter Price: ";
        cin >> price;
    }

    // Simple function to print a row using basic tabs (\t)
    void printDetails() {
        cout << bookId << "\t\t" << bookName << "\t\t" << author << "\t\t" << price << endl;
    }

    // A simple getter function to pass the price to main()
    double getPrice() {
        return price;
    }
};

int main() {
    int n;
    cout << "How many books do you want to enter? ";
    cin >> n;

    // Creating a standard array of 100 books
    Book books[100]; 

    // Loop to take input for 'n' books
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Book " << i + 1 << ":" << endl;
        books[i].getDetails();
    }

    // Printing the table headers using tabs
    cout << "\nBookID\t\tName\t\tAuthor\t\tPrice" << endl;
    cout << "------------------------------------------------------------" << endl;

    double total = 0;

    // Loop to display books and calculate total price
    for (int i = 0; i < n; i++) {
        books[i].printDetails();
        total = total + books[i].getPrice(); // Adding each book's price to total
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Total Price of all books: " << total << endl;

    return 0;
}