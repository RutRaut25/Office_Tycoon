//1)	Method Overloading – Arithmetic Operations
//Create a class Calculator with overloaded methods add() to:
//•	Add two integers 
//•	Add three integers 
//•	Add two double values 
//Demonstrate compile-time polymorphism by calling different versions of the method.

class Calculator {

    // Add two integers
    void add(int a, int b) {
        System.out.println("Sum of 2 integers: " + (a + b));
    }

    // Add three integers
    void add(int a, int b, int c) {
        System.out.println("Sum of 3 integers: " + (a + b + c));
    }

    // Add two double values
    void add(double a, double b) {
        System.out.println("Sum of 2 double values: " + (a + b));
    }
}

public class Ass_1 {

    public static void main(String[] args) {

        // Creating object
        Calculator obj = new Calculator();

        // Calling overloaded methods
        obj.add(10, 20);
        obj.add(5, 10, 15);
        obj.add(2.5, 3.5);
    }
}