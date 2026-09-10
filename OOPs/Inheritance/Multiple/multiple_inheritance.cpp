#include<bits/stdc++.h>
using namespace std;

// Multiple Inheritance : A class inherits from more than one
// parent/base class.
//
//                  People
//                 /      \
//            inherits   inherits
//              ↓          ↓
//           Teacher    Researcher
//              \          /
//               \        /
//                ↓      ↓
//                 Professor
//
// Professor inherits from TWO classes:
//     Teacher
//     Researcher
//
// Therefore, Professor demonstrates Multiple Inheritance.


// Parent / Base Class
class People{
    private:
    int mobileNo;

    public:

    People(){
        cout<<"People class constructor called"<<endl;
    }

    // Method of People class
    void walk(){
        cout<<"Walks"<<endl;
    }
};


// Child / Base Class for Professor
// Teacher inherits from People.
class Teacher : public People{
    private:
    int mobileNo;

    public:

    Teacher(){
        cout<<"Teacher class constructor called"<<endl;
    }

    // Method specific to Teacher
    void teach(){
        cout<<"Teacher teaches"<<endl;
    }
};


// Child / Base Class for Professor
// Researcher also inherits from People.
class Researcher : public People{
    private:
    int mobileNo;

    public:

    Researcher(){
        cout<<"Researcher class constructor called"<<endl;
    }

    // Method specific to Researcher
    void teachInCollege(){
        cout<<"Researcher do research"<<endl;
    }
};


// Professor inherits from TWO classes:
//     Teacher
//     Researcher
//
// This is Multiple Inheritance.
//
// Professor gets functionality from both Teacher and Researcher.
class Professor : public Teacher, public Researcher{
    private:
    int mobileNo;

    public:

    Professor(){
        cout<<"Professor class constructor called"<<endl;
    }

    // Method specific to Professor
    void research(){
        cout<<"Professor teaches in UG/PG colleges"<<endl;
    }
};


int main() {

    // Creating objects of the individual classes.
    Teacher T1;
    Researcher R1;

    // Creating an object of Professor.
    // Professor inherits from both Teacher and Researcher.
    Professor P1;


    // Teacher inherits walk() from People.
    T1.walk();

    // Researcher also inherits walk() from People.
    R1.walk();


    // ERROR: Ambiguous call

    // P1.walk();
    // Professor has TWO paths to People:
    //
    // Professor
    //    ├── Teacher → People → walk()
    //    │
    //    └── Researcher → People → walk()
    //
    // Therefore, the compiler cannot determine which
    // walk() function should be called.
    // This leads to Diamond Problem.


    return 0;
}