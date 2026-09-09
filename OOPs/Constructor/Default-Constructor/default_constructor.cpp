#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string name;
    int empID;

public:

    // No constructor is explicitly defined in this class.
    //
    // Therefore, If we don't declare any constructor, the compiler implicitly declares a default constructor for the class.
    //
    // Employee emp1;  → compiler-generated default constructor
    //
    // The compiler-generated constructor performs default
    // construction of the data members.
    //
    // name  → string is default-constructed to an empty string
    // empID → int is NOT automatically initialized to 0
    //
    // For a local object, empID therefore has an
    // indeterminate value until we assign a value to it.


    // Setter method
    // Used to assign values to the private attributes.
    void setEmployee(string name, int empID) {
        this->name = name;
        this->empID = empID;
    }


    // Getter method
    // Used to display the private attributes.
    void getEmployee() {
        cout << "Employee name : " << name << endl;
        cout << "Employee ID : " << empID << endl;
    }
};

int main() {

    // No constructor is explicitly called here.
    //
    // Since we did not define any constructor in Employee,
    // the compiler provides a default constructor automatically.
    Employee emp1;

    // Assign values to the object's attributes.
    emp1.setEmployee("Suresh", 202232);

    // Display employee information.
    emp1.getEmployee();

    return 0;
}