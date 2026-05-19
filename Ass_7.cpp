//Design and implement a C++ program to demonstrate inheritance using the following
//employee hierarchy:
//Base Class: Employee with data members: Emp_name, Emp_id, Address, Mail_id, and
//Mobile_no.
//Derived Classes: Programmer, TeamLead, AssistantProjectManager, and
//ProjectManager. Each derived class should have an additional data member Basic Pay
//(BP).
//Salary components for all employees are calculated as:
//Dearness Allowance (DA): 52% of BP
//House Rent Allowance (HRA): 27% of BP
//Provident Fund (PF): 12% of BP
//Staff Club Fund: 0.1% of BP
//Implement member functions to calculate gross and net salary and generate pay slips
//for all employees.

#include <iostream>
using namespace std;

class Employee {
protected:
    string Emp_name;
    int Emp_id;
    string Address;
    string Mail_id;
    long long Mobile_no;

public:
    void getEmployeeDetails() {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, Emp_name);

        cout << "Enter Employee ID: ";
        cin >> Emp_id;

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, Address);

        cout << "Enter Mail ID: ";
        getline(cin, Mail_id);

        cout << "Enter Mobile Number: ";
        cin >> Mobile_no;
    }

    void displayEmployeeDetails() {
        cout << "\nEmployee Name : " << Emp_name << endl;
        cout << "Employee ID   : " << Emp_id << endl;
        cout << "Address       : " << Address << endl;
        cout << "Mail ID       : " << Mail_id << endl;
        cout << "Mobile No     : " << Mobile_no << endl;
    }
};

class Programmer : public Employee {
private:
    float BP, DA, HRA, PF, SCF, Gross, Net;

public:
    void getBasicPay() {
        cout << "Enter Basic Pay: ";
        cin >> BP;
    }

    void calculateSalary() {
        DA = 0.52 * BP;
        HRA = 0.27 * BP;
        PF = 0.12 * BP;
        SCF = 0.001 * BP;
        Gross = BP + DA + HRA;
        Net = Gross - PF - SCF;
    }

    void generatePaySlip() {
        displayEmployeeDetails();
        cout << "\n----- Pay Slip (Programmer) -----\n";
        cout << "Basic Pay        : " << BP << endl;
        cout << "DA (52%)         : " << DA << endl;
        cout << "HRA (27%)        : " << HRA << endl;
        cout << "PF (12%)         : " << PF << endl;
        cout << "Staff Club Fund  : " << SCF << endl;
        cout << "Gross Salary     : " << Gross << endl;
        cout << "Net Salary       : " << Net << endl;
    }
};

class TeamLead : public Programmer {};
class AssistantProjectManager : public Programmer {};
class ProjectManager : public Programmer {};

int main() {
    int choice;

    cout << "Select Employee Type:\n";
    cout << "1. Programmer\n";
    cout << "2. Team Lead\n";
    cout << "3. Assistant Project Manager\n";
    cout << "4. Project Manager\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {

        case 1: {
            Programmer p;
            p.getEmployeeDetails();
            p.getBasicPay();
            p.calculateSalary();
            p.generatePaySlip();
            break;
        }

        case 2: {
            TeamLead t;
            t.getEmployeeDetails();
            t.getBasicPay();
            t.calculateSalary();
            t.generatePaySlip();
            break;
        }

        case 3: {
            AssistantProjectManager a;
            a.getEmployeeDetails();
            a.getBasicPay();
            a.calculateSalary();
            a.generatePaySlip();
            break;
        }

        case 4: {
            ProjectManager pm;
            pm.getEmployeeDetails();
            pm.getBasicPay();
            pm.calculateSalary();
            pm.generatePaySlip();
            break;
        }

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}
 