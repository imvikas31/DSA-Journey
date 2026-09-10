#include<bits/stdc++.h>
using namespace std;


// Copy Constructor : A special constructor that creates a new object
// by copying the data of an existing object.
//
// Syntax:
// ClassName(const ClassName &object);
//
// In this example:
// s1 → Existing object
// s2 → New object created as a copy of s1


class Student{
    public:
    string name;
    int id;


    // Parameterized Constructor
    // Used to create the original Student object.
    Student(string name, int id){
        this->name = name;
        this->id = id;

        cout<<"Student created."<<endl;
    }


    // Copy Constructor
    //
    // Receives an existing Student object by const reference
    // and copies its data into the newly created object.
    //
    // s1 → Existing object
    // s2 → New object
    //
    // When Student s2(s1) is executed, this constructor is called.
    Student(const Student &s1){

        // Copy data from the existing object to the new object.
        this->name = s1.name;
        this->id = s1.id;

        cout<<"Copy of Student created."<<endl;
    }
};


int main() {

    // Creating the original Student object.
    // Parameterized constructor is called.
    Student s1("Vikas Singh",112);


    // Creating a new Student object by copying s1.
    // Copy constructor is called here.
    Student s2(s1);


    // s2 contains the copied data of s1.
    cout<<s2.name<<endl;
    cout<<s2.id<<endl;
    
    return 0;
}