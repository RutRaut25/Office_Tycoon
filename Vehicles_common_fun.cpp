//Design and implement an interface for Vehicles to represent common functionalities.
//Consider vehicles such as Bicycle, Bike, and Car, which share the following
//functionalities:
//• gearChange()
//• speedUp()
//• applyBrakes()
//Create an interface Vehicle that declares these methods. Implement the interface in the
//classes Bicycle, Bike, and Car, providing custom implementations for each method
//according to the specific vehicle type.

#include <iostream>
using namespace std;

// Interface (Abstract Class)
class Vehicle {
public:
    virtual void gearChange(int g) = 0;
    virtual void speedUp(int s) = 0;
    virtual void applyBrakes(int b) = 0;
};

// Bicycle Class
class Bicycle : public Vehicle {
private:
    int gear, speed;

public:
    Bicycle() {
        gear = 1;
        speed = 0;
    }

    void gearChange(int g) {
        gear = g;
        cout << "Bicycle gear changed to " << gear << endl;
    }

    void speedUp(int s) {
        speed += s;
        cout << "Bicycle speed increased to " << speed << endl;
    }

    void applyBrakes(int b) {
        speed -= b;
        cout << "Bicycle speed decreased to " << speed << endl;
    }
};

// Bike Class
class Bike : public Vehicle {
private:
    int gear, speed;

public:
    Bike() {
        gear = 1;
        speed = 0;
    }

    void gearChange(int g) {
        gear = g;
        cout << "Bike gear changed to " << gear << endl;
    }

    void speedUp(int s) {
        speed += s;
        cout << "Bike speed increased to " << speed << endl;
    }

    void applyBrakes(int b) {
        speed -= b;
        cout << "Bike speed decreased to " << speed << endl;
    }
};

// Car Class
class Car : public Vehicle {
private:
    int gear, speed;

public:
    Car() {
        gear = 1;
        speed = 0;
    }

    void gearChange(int g) {
        gear = g;
        cout << "Car gear changed to " << gear << endl;
    }

    void speedUp(int s) {
        speed += s;
        cout << "Car speed increased to " << speed << endl;
    }

    void applyBrakes(int b) {
        speed -= b;
        cout << "Car speed decreased to " << speed << endl;
    }
};

int main() {
    Bicycle b1;
    Bike b2;
    Car c1;

    cout << "\n--- Bicycle ---\n";
    b1.gearChange(2);
    b1.speedUp(10);
    b1.applyBrakes(3);

    cout << "\n--- Bike ---\n";
    b2.gearChange(4);
    b2.speedUp(40);
    b2.applyBrakes(10);

    cout << "\n--- Car ---\n";
    c1.gearChange(5);
    c1.speedUp(60);
    c1.applyBrakes(20);

    return 0;
}
