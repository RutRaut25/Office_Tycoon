//Write a C++ program to create a Student class with the following:
//Private data members: Roll Number, Name, Marks of five subjects, Percentage,
//Result Division
//Public members: Parameterized constructor, destructor, functions to calculate
//percentage, determine grade/division, and display student details
//Implement a friend function comparePercentage() that takes two Student objects
//and displays the one with the higher percentage.
#include<iostream>
using namespace std;

class Student
{
    int roll;
    string name;
    int marks[5];
    float percentage;
    string division;

public:
    Student(int r, string n, int m[])
    {
        roll = r;
        name = n;
        for(int i=0;i<5;i++)
            marks[i] = m[i];
        percentage = 0;
    }

    ~Student()
    {
    }

    void calculatePercentage()
    {
        int total = 0;
        for(int i=0;i<5;i++)
            total += marks[i];
        percentage = total / 5.0;
    }

    void determineDivision()
    {
        if(percentage >= 75)
            division = "Distinction";
        else if(percentage >= 60)
            division = "First Class";
        else if(percentage >= 50)
            division = "Second Class";
        else if(percentage >= 40)
            division = "Pass Class";
        else
            division = "Fail";
    }

    void display()
    {
        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nPercentage: " << percentage;
        cout << "\nResult: " << division << endl;
    }

    friend void comparePercentage(Student, Student);
};

void comparePercentage(Student s1, Student s2)
{
    cout << "\nStudent with Higher Percentage:\n";
    if(s1.percentage > s2.percentage)
        s1.display();
    else if(s2.percentage > s1.percentage)
        s2.display();
    else
    {
        cout << "\nBoth students have equal percentage";
        s1.display();
        s2.display();
    }
}

int main()
{
    int roll;
    string name;
    int marks[5];

    cout << "Enter details of Student 1\n";
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks of 5 subjects:\n";
    for(int i=0;i<5;i++)
        cin >> marks[i];

    Student s1(roll, name, marks);
    s1.calculatePercentage();
    s1.determineDivision();

    cout << "\nEnter details of Student 2\n";
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks of 5 subjects:\n";
    for(int i=0;i<5;i++)
        cin >> marks[i];

    Student s2(roll, name, marks);
    s2.calculatePercentage();
    s2.determineDivision();

    comparePercentage(s1, s2);

    return 0;
}