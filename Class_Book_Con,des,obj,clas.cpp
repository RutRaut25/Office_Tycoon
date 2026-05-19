//Write a C++ program to implement a class Book with suitable data members. Use
//constructors to initialize book details and a destructor to indicate object destruction,
//thereby demonstrating the concepts of objects, classes, constructors, and destructors.

#include <iostream>
#include <string>

class Book {
private:
    // Data members
    std::string title;
    std::string author;
    double price;

public:
    // Default Constructor
    Book() {
        title = "Unknown Title";
        author = "Unknown Author";
        price = 0.0;
        std::cout << "[Constructor] Default constructor called. Empty book created.\n";
    }

    // Parameterized Constructor
    Book(std::string t, std::string a, double p) {
        title = t;
        author = a;
        price = p;
        std::cout << "[Constructor] Parameterized constructor called for: \"" << title << "\"\n";
    }

    // Destructor
    ~Book() {
        std::cout << "[Destructor] Destructor called. Object for \"" << title << "\" is being destroyed.\n";
    }

    // Member function to display book details
    void displayDetails() const {
        std::cout << "--- Book Details ---\n";
        std::cout << "Title:  " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Price:  $" << price << "\n";
        std::cout << "--------------------\n\n";
    }
};

int main() {
    std::cout << "=== Program Starting ===\n\n";

    // Creating an object using the parameterized constructor
    std::cout << "Creating book1...\n";
    Book book1("The Hobbit", "J.R.R. Tolkien", 14.99);
    book1.displayDetails();

    // Creating an object using the default constructor inside a nested block
    // This helps visualize exactly when a destructor is triggered
    {
        std::cout << "Entering a local scope block...\n";
        std::cout << "Creating book2...\n";
        Book book2; 
        book2.displayDetails();
        std::cout << "Exiting the local scope block...\n";
    } // book2 goes out of scope and is destroyed here

    std::cout << "\nBack in main scope. Program is about to finish...\n";
    
    return 0;
} // book1 goes out of scope and is destroyed here
