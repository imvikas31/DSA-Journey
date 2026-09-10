#include<bits/stdc++.h>
using namespace std;


// Non-Parameterized Constructor :
// A constructor that does not take any arguments.
//
// It is automatically called when an object is created
// without providing constructor arguments.
//
// Example:
// Student s1;
//       ↓
// Default constructor is called


class Student{
    public:
    string name;
    int id;


    // Default Constructor
    // It takes no parameters.
    Student(){

        // If we explicitly initialize the members, they would
        // receive these values.
        //
        // name = "Vikas Singh";
        // id = 112;

        cout<<"Student created."<<endl;
    }
};


int main() {

    // Creating an object without passing any arguments.
    // The default constructor is automatically called.
    Student s1;

    // name is a string, so it is default-initialized to an empty string.
    cout<<s1.name<<endl;

    // id is an int and is not explicitly initialized.
    // For a local object like s1, its value is indeterminate.
    // Reading it is undefined behavior.
    cout<<s1.id<<endl;
    
    return 0;
}