//2)	Design and implement a Java application to calculate the area of different geometric shapes—Circle, Rectangle, and Triangle—using hierarchical inheritance.
//Create a base class Shape that defines a general method area(). Then derive three classes Circle, Rectangle, and Triangle from Shape. Each derived class must override the area() method to compute the area based on its specific formula.
//The program should accept input values for each shape, create corresponding objects, and display the calculated areas using runtime polymorphism (base class reference).

import java.util.Scanner;

// Base class
class Shape {

    void area() {
        System.out.println("Area of Shape");
    }
}

// Circle class
class Circle extends Shape {

    double r;

    Circle(double r) {
        this.r = r;
    }

    void area() {
        double a = 3.14 * r * r;
        System.out.println("Area of Circle: " + a);
    }
}

// Rectangle class
class Rectangle extends Shape {

    double l, b;

    Rectangle(double l, double b) {
        this.l = l;
        this.b = b;
    }

    void area() {
        double a = l * b;
        System.out.println("Area of Rectangle: " + a);
    }
}

// Triangle class
class Triangle extends Shape {

    double b, h;

    Triangle(double b, double h) {
        this.b = b;
        this.h = h;
    }

    void area() {
        double a = 0.5 * b * h;
        System.out.println("Area of Triangle: " + a);
    }
}

public class Ass_2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Shape s;

        // Circle
        System.out.print("Enter radius of circle: ");
        double r = sc.nextDouble();

        s = new Circle(r);
        s.area();

        // Rectangle
        System.out.print("Enter length of rectangle: ");
        double l = sc.nextDouble();

        System.out.print("Enter breadth of rectangle: ");
        double b = sc.nextDouble();

        s = new Rectangle(l, b);
        s.area();

        // Triangle
        System.out.print("Enter base of triangle: ");
        double base = sc.nextDouble();

        System.out.print("Enter height of triangle: ");
        double h = sc.nextDouble();

        s = new Triangle(base, h);
        s.area();

        sc.close();
    }
}
