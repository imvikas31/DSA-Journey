#include<bits/stdc++.h>
using namespace std;


// Parameterized Constructor : A constructor that accepts one or more
// parameters and uses them to initialize the object's data members.
//
// In this example:
// Student(name, id)
//       ↓
// Initializes name and id of the Student object.


class Student{
    public:
    string name;
    int id;


    // Parameterized Constructor
    // Takes name and id as arguments while creating the object.
    Student(string name, int id){

        // 'this->name' refers to the object's data member.
        // 'name' refers to the constructor parameter.
        this->name = name;

        // Assign the parameter id to the object's id member.
        this->id = id;

        cout<<"Student created."<<endl;
    }
};


int main() {

    // Creating a Student object using the parameterized constructor.
    // The values "Vikas Singh" and 112 are passed as arguments.
    Student s1("Vikas Singh",112);

    // Accessing the initialized data members.
    cout<<s1.name<<endl;
    cout<<s1.id<<endl;
    
    return 0;
}