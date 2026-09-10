#include <bits/stdc++.h>
using namespace std;

// Hierarchical Inheritance : Multiple child/derived classes inherit
// from the same single parent/base class.
//
//                 Parent / Base Class
//                       Animal
//                      /      \
//                 inherits   inherits
//                    ↓          ↓
//                  Dog         Cat
//             Child Class   Child Class
//
// Here:
// Animal → Dog
// Animal → Cat
//
// Dog and Cat both inherit from the same parent class: Animal.
// Therefore, multiple child classes share the same base class.


// Parent / Base Class
class Animal {
public:

    // Method of the Parent Class
    // This method is inherited by both Dog and Cat.
    void eat() {
        cout << "This animal eats food." << endl;
    }
};


// Child / Derived Class
// Dog inherits from Animal.
class Dog : public Animal {
public:

    // Method specific to Dog
    void bark() {
        cout << "This dog barks." << endl;
    }
};


// Child / Derived Class
// Cat also inherits from Animal.
class Cat : public Animal {
public:

    // Method specific to Cat
    void meow() {
        cout << "This cat meows." << endl;
    }
};


int main() {

    // Creating objects of both child classes.
    Dog dog;
    Cat cat;


    // Dog can access the inherited eat() method from Animal.
    dog.eat();

    // Dog can also access its own bark() method.
    dog.bark();


    // Cat can access the inherited eat() method from Animal.
    cat.eat();

    // Cat can also access its own meow() method.
    cat.meow();


    return 0;
}