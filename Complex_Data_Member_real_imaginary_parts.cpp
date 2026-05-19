//Design a C++ class Complex with data members to store the real and imaginary parts.
//Provide default and parameterized constructors. Implement operator overloading
//for +, -, and * to perform arithmetic operations on complex numbers. Write a program
//that creates two complex objects and displays the results of these operations.

#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator * (Complex c) {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 4);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "Product: ";
    prod.display();

    return 0;
}
