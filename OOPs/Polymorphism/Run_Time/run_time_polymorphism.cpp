#include<bits/stdc++.h>
using namespace std;


// ============================================================
// RUNTIME POLYMORPHISM
// ============================================================
//
// Runtime Polymorphism means the function to be executed is
// determined at runtime based on the actual object.
//
// It is commonly achieved using:
// 1. Inheritance
// 2. Function Overriding
// 3. Virtual Function
// 4. Base class pointer/reference
//
// In this example:
//
//              Animal
//             /      \
//            ↓        ↓
//          Dog        Cat
//
// Both Dog and Cat override the sound() function of Animal.
// ============================================================


// Base / Parent Class
class Animal {
public:

    // Virtual function enables runtime polymorphism.
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};


// Derived / Child Class
class Dog : public Animal {
public:

    // Overriding the sound() function of Animal.
    void sound() override {
        cout << "Dog barks" << endl;
    }
};


// Another Derived / Child Class
class Cat : public Animal {
public:

    // Overriding the sound() function of Animal.
    void sound() override {
        cout << "Cat meows" << endl;
    }
};


int main() {

    Dog dog;
    Cat cat;

    // Base class pointer.
    Animal* animal;


    // Pointer points to Dog object.
    animal = &dog;

    // Runtime determines that the actual object is Dog,
    // so Dog::sound() is called.
    animal->sound();


    // Pointer now points to Cat object.
    animal = &cat;

    // Runtime determines that the actual object is Cat,
    // so Cat::sound() is called.
    animal->sound();


    return 0;
}