# Non-Parameterized Constructor in C++

## Overview

A **Non-Parameterized Constructor** is a constructor that **does not accept any parameters**.

It is called when an object is created without passing any arguments.

### Syntax

```cpp
class Student {
public:

    Student() {
        // Constructor body
    }
};
```

---

## Example

```cpp
class Student {
public:
    string name;
    int id;

    // Non-Parameterized Constructor
    Student() {
        cout << "Student created." << endl;
    }
};
```

Creating an object:

```cpp
Student s1;
```

Since no arguments are provided, the non-parameterized constructor is called automatically.

```text
Student s1;
     ↓
Student()
     ↓
Object created
```

---

## Initialization

A non-parameterized constructor **can initialize data members**, but it does not receive values from the caller.

For example:

```cpp
Student() {
    name = "Vikas Singh";
    id = 112;
}
```

Here, the constructor is still non-parameterized because it takes **zero parameters**.

If no initialization is provided:

```cpp
Student() {
    cout << "Student created." << endl;
}
```

then:

* `string name` is default-constructed as an empty string.
* `int id` remains uninitialized for an ordinary local object.

---

## Key Takeaway

> **Non-Parameterized Constructor = Constructor with zero parameters.**

```text
No arguments
     ↓
Student s1;
     ↓
Student()
```
