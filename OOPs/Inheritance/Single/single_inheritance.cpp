#include<bits/stdc++.h>
using namespace std;

// Inheritance : Allows a class to inherit or extend the functionality of another class.
// The class that inherits from another class is called the Child / Derived / Sub class.
// The class whose functionality is inherited is called the Parent / Base / Super class.

// Single Inheritance : A class inherits from a single parent class.
//
//        Parent Class
//             School
//               |
//               | inherits
//               ↓
//        Child Class
//            Student
//
// Here, Student inherits from only one parent class: School.


// Parent / Base Class
class School{
    private:
    string schoolName;

    public:

    // Constructor of Parent Class
    School(){
        schoolName = "DPS";
    }

    // Method of Parent Class
    void printSchoolName(){
        cout<<"School Name is : "<<schoolName<<endl;
    }
};


// Child / Derived Class
// Student inherits from School using public inheritance.
class Student : public School{
    private:
    string studentName;

    public:

    // Constructor of Child Class
    Student(string studentName){
        this->studentName = studentName;
    }

    // Method of Child Class
    void printStudentName(){
        cout<<"School Name is : "<<studentName<<endl;
    }
};


int main() {

    // Creating an object of the Child class.
    Student student1("Vikas Singh");

    // Student inherits printSchoolName() from the School class.
    // Therefore, a Student object can access the public methods of School.
    student1.printSchoolName();

    // Student also has its own method printStudentName().
    student1.printStudentName();
    
    return 0;
}