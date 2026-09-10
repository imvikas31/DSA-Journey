#include <bits/stdc++.h>
using namespace std;

// Multilevel Inheritance : A class inherits from another derived class,
// forming a chain of inheritance.
//
//        Parent / Base Class
//              Animal
//                |
//                | inherits
//                ↓
//        Intermediate Class
//              Mammal
//                |
//                | inherits
//                ↓
//          Child Class
//               Dog
//
// Here:
// Animal → Mammal → Dog
//
// Dog directly inherits from Mammal.
// Mammal directly inherits from Animal.
// Therefore, Dog indirectly inherits the functionality of Animal.


// Parent / Base Class
class Animal {

public:

    // Method of Animal class
    void eat() {
        cout << "This animal eats food." << endl;
    }
};


// Intermediate / Derived Class
// Mammal inherits from Animal.
class Mammal : public Animal {

public:

    // Method of Mammal class
    void walk() {
        cout << "This mammal walks." << endl;
    }
};


// Child / Derived Class
// Dog inherits from Mammal.
class Dog : public Mammal {

public:

    // Method of Dog class
    void bark() {
        cout << "This dog barks." << endl;
    }
};


// Main function to demonstrate Multilevel Inheritance
int main() {

    // Creating an object of the final derived class.
    Dog dog;

    // Dog can access eat() because:
    // Dog inherits from Mammal,
    // and Mammal inherits from Animal.
    dog.eat();

    // Dog can directly access walk()
    // because Dog inherits from Mammal.
    dog.walk();

    // Dog can access its own method.
    dog.bark();

    return 0;
}