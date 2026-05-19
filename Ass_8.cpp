//Design a base class Shape with two double-type data members to represent the
//dimensions of the shape. Include member functions to input the dimensions and a
//pure virtual function compute_area() for calculating the area.
//Derive two classes: Triangle and Rectangle from Shape and override the
//compute_area() function to calculate the area according to the specific shape.
//Write a program that:
//a) Accepts the dimensions of a triangle or rectangle from the user.
//b) Uses dynamic binding to call the appropriate compute_area() function.
//c) Displays the calculated area of the shape.

#include<iostream>
using namespace std;

class Shape
{
protected:
    double d1,d2;

public:
    void getData()
    {
        cout<<"Enter first dimension: ";
        cin>>d1;
        cout<<"Enter second dimension: ";
        cin>>d2;
    }

    virtual double compute_area()=0;
};

class Triangle:public Shape
{
public:
    double compute_area()
    {
        return 0.5*d1*d2;
    }
};

class Rectangle:public Shape
{
public:
    double compute_area()
    {
        return d1*d2;
    }
};

int main()
{
    Shape *s;
    Triangle t;
    Rectangle r;
    int choice;

    cout<<"1. Triangle"<<endl;
    cout<<"2. Rectangle"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    if(choice==1)
    {
        s=&t;
        s->getData();
        cout<<"Area of Triangle = "<<s->compute_area();
    }
    else if(choice==2)
    {
        s=&r;
        s->getData();
        cout<<"Area of Rectangle = "<<s->compute_area();
    }

    return 0;
}