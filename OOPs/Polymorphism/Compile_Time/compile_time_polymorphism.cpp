#include<bits/stdc++.h>
using namespace std;


// ============================================================
// COMPILE-TIME POLYMORPHISM
// ============================================================
//
// Compile-Time Polymorphism means the compiler determines
// which function or operator to use at compile time.
//
// This example demonstrates two ways:
// 1. Function Overloading
// 2. Operator Overloading
// ============================================================



// ============================================================
// 1. FUNCTION OVERLOADING
// ============================================================
//
// Function Overloading : Multiple functions can have the same
// name but different parameter lists.
//
// The compiler identifies the correct add() function based on
// the number and type of arguments passed.
// ============================================================

class Add{
    public:

    // Constructor of Add class
    Add(){
        cout<<"Add class constructor called"<<endl;
    }


    // add() with two integer parameters
    int add(int a, int b){
        return a+b;
    }


    // add() with three integer parameters
    // Different number of parameters → different signature.
    int add(int a, int b, int c){
        return a+b+c;
    }


    // add() with two double parameters
    // Different parameter types → different signature.
    double add(double a, double b){
        return a+b;
    }


    // add() with three double parameters
    double add(double a, double b, double c){
        return a+b+c;
    }
};



// ============================================================
// 2. OPERATOR OVERLOADING
// ============================================================
//
// Operator Overloading allows us to define how an existing
// operator behaves when used with objects.
//
// Here, we overload the '+' operator for Complex objects.
//
// Normally:
//     int + int
//
// But here we want:
//     Complex + Complex
//
// The compiler maps:
//     A + B
//
// to:
//     A.operator+(B)
// ============================================================

class Complex{
    public:
    int real;
    int img;


    // Parameterized constructor
    Complex(int real, int img){
        this->real = real;
        this->img = img;

        cout<<"Complex number created"<<endl;
    }


    // Overloading the '+' operator.
    //
    // This function is called when two Complex objects
    // are added using the '+' operator.
    Complex operator+ (const Complex &B){

        // Create a temporary Complex object.
        Complex temp(0,0);

        // Add the real parts.
        temp.real = this->real + B.real;

        // Add the imaginary parts.
        temp.img = this->img + B.img;

        // Return the resulting Complex object.
        return temp;
    }


    // Display the complex number.
    void printComplexNum(){
        printf("[%d, i%d]",this->real, this->img);
        cout<<endl;
    }
};



int main() {

    // ========================================================
    // Function Overloading
    // ========================================================

    // Creating an object of Add class.
    Add add1;


    // Compiler selects add(int, int).
    add1.add(2,3);


    // Compiler selects add(int, int, int).
    add1.add(2,3,5);


    // Compiler selects add(double, double).
    add1.add(2.2,3.0);


    // Compiler selects add(double, double, double).
    add1.add(2.2,3.0,5.5);



    // ========================================================
    // Operator Overloading
    // ========================================================

    // Creating two Complex objects.
    Complex A(2,5);
    Complex B(4,3);

    A.printComplexNum();
    B.printComplexNum();


    // '+' operator is overloaded for Complex objects.
    //
    // A + B
    //
    // is internally treated as:
    //
    // A.operator+(B)
    //
    // The result is stored in C.
    Complex C = A + B;

    C.printComplexNum();


    return 0;
}