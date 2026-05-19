//Identify the commonalities and differences between the classes Publication, Book,
//and Magazine. The classes share the following common instance variables: title,
//price, and copies, and a common method: saleCopy().
//The Book class has an additional data member author and a method orderCopies().
//The Magazine class has additional methods orderQty(), currentIssue(), and
//receiveIssue().
//Write a program to:
//a) Create objects of the classes.
//b) Find and display the number of copies ordered for each book.
//c) Calculate and display the total sales of all publications.#include <iostream>


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Publication {
protected:
    string title;
    double price;
    int copies;

public:
    Publication(string t, double p, int c) : title(t), price(p), copies(c) {}

    virtual ~Publication() {}

    virtual void saleCopy(int qty) {
        if (qty <= copies) {
            copies -= qty;
        } else {
            cout << "Not enough copies available for " << title << endl;
        }
    }

    double getPrice() const { return price; }
    int getCopies() const { return copies; }
    string getTitle() const { return title; }
};

class Book : public Publication {
private:
    string author;
    int orderedCopies;

public:
    Book(string t, double p, int c, string a) 
        : Publication(t, p, c), author(a), orderedCopies(0) {}

    void orderCopies(int qty) {
        orderedCopies += qty;
        copies += qty;
    }

    int getOrderedCopies() const {
        return orderedCopies;
    }
};

class Magazine : public Publication {
private:
    int orderQuantity;
    string currentIssueMonth;

public:
    Magazine(string t, double p, int c, int oQty, string issue) 
        : Publication(t, p, c), orderQuantity(oQty), currentIssueMonth(issue) {}

    void orderQty(int qty) {
        orderQuantity = qty;
    }

    string currentIssue() {
        return currentIssueMonth;
    }

    void receiveIssue(string newIssue) {
        currentIssueMonth = newIssue;
        copies += orderQuantity;
    }
};

int main() {
    vector<Book*> bookstore;
    vector<Magazine*> newsstand;

    Book* b1 = new Book("The C++ Programming Language", 50.0, 10, "Bjarne Stroustrup");
    Book* b2 = new Book("Effective Modern C++", 45.0, 5, "Scott Meyers");

    Magazine* m1 = new Magazine("Tech Monthly", 9.99, 20, 50, "May");
    Magazine* m2 = new Magazine("Science Today", 12.50, 15, 30, "June");

    bookstore.push_back(b1);
    bookstore.push_back(b2);

    newsstand.push_back(m1);
    newsstand.push_back(m2);

    b1->orderCopies(15);
    b2->orderCopies(20);

    for (const auto& book : bookstore) {
        cout << "Book: \"" << book->getTitle() << "\" -> Copies Ordered: " << book->getOrderedCopies() << endl;
    }
    cout << endl;

    double totalSales = 0.0;

    b1->saleCopy(5);
    totalSales += 5 * b1->getPrice();

    b2->saleCopy(10);
    totalSales += 10 * b2->getPrice();

    m1->saleCopy(8);
    totalSales += 8 * m1->getPrice();

    m2->saleCopy(12);
    totalSales += 12 * m2->getPrice();

    cout << "Total Sales of all publications: $" << totalSales << endl;

    for (auto b : bookstore) delete b;
    for (auto m : newsstand) delete m;

    return 0;
}