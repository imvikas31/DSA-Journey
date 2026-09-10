# Single Inheritance in C++

## Overview

**Single Inheritance** is a type of inheritance where **one child/derived class inherits from one parent/base class**.

In this example:

```text
        School
     Parent/Base
          |
          | inherits
          ↓
       Student
     Child/Derived
```

The `Student` class inherits from the `School` class.

---

## Code

```cpp
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
```

---

## What is Single Inheritance?

In **Single Inheritance**, a derived class has **exactly one direct base class**.

For example:

```cpp
class Student : public School
{
};
```

Here:

* `School` → Parent/Base class
* `Student` → Child/Derived class
* `public` → inheritance mode
* `Student` inherits from `School`

The relationship can be represented as:

```text
School
  |
  | inherits
  ↓
Student
```

---

## Parent Class

The `School` class acts as the **Parent/Base class**.

```cpp
class School{
private:
    string schoolName;

public:
    School(){
        schoolName = "DPS";
    }

    void printSchoolName(){
        cout << "School Name is : " << schoolName << endl;
    }
};
```

The class provides the functionality that the child class can use.

In this example, the important inherited functionality is:

```cpp
printSchoolName()
```

---

## Child Class

The `Student` class acts as the **Child/Derived class**.

```cpp
class Student : public School
```

This statement establishes the inheritance relationship:

```text
Student → School
```

Because `Student` inherits from `School`, a `Student` object can access the public functionality inherited from `School`.

---

## Accessing Inherited Functionality

In `main()`:

```cpp
Student student1("Vikas Singh");
```

creates an object of the `Student` class.

The object can then call:

```cpp
student1.printSchoolName();
```

Even though `printSchoolName()` is defined inside `School`, it can be accessed through the `Student` object because `Student` inherits from `School`.

---

## Child's Own Functionality

Inheritance does not mean that the child class can only use functionality from the parent.

The child class can also have its own functionality.

In this example:

```cpp
void printStudentName(){
    cout << "School Name is : " << studentName << endl;
}
```

is defined inside `Student`.

Therefore:

```cpp
student1.printStudentName();
```

calls a method belonging to `Student`.

So the `Student` object can use:

```text
Student object
      |
      ├── Inherited functionality
      │      └── printSchoolName()
      │
      └── Its own functionality
             └── printStudentName()
```

---

## Execution Flow

When the program executes:

### 1. Create Student object

```cpp
Student student1("Vikas Singh");
```

A `Student` object is created.

### 2. Access inherited method

```cpp
student1.printSchoolName();
```

The method comes from the `School` class.

Output:

```text
School Name is : DPS
```

### 3. Access Student's own method

```cpp
student1.printStudentName();
```

The method belongs to the `Student` class.

Output:

```text
School Name is : Vikas Singh
```

### Final Output

```text
School Name is : DPS
School Name is : Vikas Singh
```

---

## Key Point Demonstrated

This example demonstrates the basic idea of **Single Inheritance**:

```text
One Parent
    ↓
One Child
```

Specifically:

```text
School
  ↓
Student
```

`Student` inherits functionality from `School` and can additionally define its own functionality.

---

## Syntax

The general syntax for single inheritance is:

```cpp
class Child : public Parent
{
    // Child class members
};
```

For this example:

```cpp
class Student : public School
{
    // Student class members
};
```

---

## Important Takeaway

> **Single Inheritance is when one derived class inherits from one base class.**

In this example:

```text
School → Student
```

`School` is the **Parent/Base class**, while `Student` is the **Child/Derived class**.
