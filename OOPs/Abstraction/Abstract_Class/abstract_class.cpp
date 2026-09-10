#include <bits/stdc++.h>
using namespace std;

// ABSTRACTION USING ABSTRACT CLASS
//
// Abstraction means hiding implementation details and showing only
// the essential functionality.
//
// An abstract class provides a common interface/contract for its
// derived classes without providing the complete implementation.

// Abstract Class
// Animal is an abstract class because it contains a pure virtual function.
class Animal {
public:

    // Pure virtual function
    // Animal only defines WHAT every animal should have: sound().
    // It does not define HOW the sound should be made.
    virtual void sound() = 0;
};

// Dog inherits from the abstract class Animal.
class Dog : public Animal {
public:

    // Dog provides the actual implementation of sound().
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Cat also inherits from the abstract class Animal.
class Cat : public Animal {
public:

    // Cat provides its own implementation of sound().
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {

    // Cannot create an object of an abstract class.
    // Animal a;

    // Dog and Cat provide implementations of sound(),
    // so they can be instantiated.
    Dog d;
    Cat c;

    // Calling the implementations provided by the derived classes.
    d.sound();
    c.sound();

    return 0;
}