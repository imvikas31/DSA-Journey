# Parameterized Constructor in C++

## Overview

A **Parameterized Constructor** is a constructor that accepts **one or more parameters** and uses them to initialize an object's data members.

### Syntax

```cpp
class ClassName {
public:
    ClassName(parameters) {
        // Initialize data members
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

    Student(string name, int id) {
        this->name = name;
        this->id = id;
    }
};
```

The constructor accepts:

```text
name → Student's name
id   → Student's ID
```

---

## Creating an Object

```cpp
Student s1("Vikas Singh", 112);
```

The values passed during object creation are received by the constructor:

```text
"Vikas Singh" ──→ name
112           ──→ id
```

The object is initialized as:

```text
s1
├── name = "Vikas Singh"
└── id   = 112
```

---

## `this` Pointer

In:

```cpp
Student(string name, int id) {
    this->name = name;
    this->id = id;
}
```

* `this->name` → object's `name` data member
* `name` → constructor parameter
* `this->id` → object's `id` data member
* `id` → constructor parameter

`this` is used to distinguish between the object's data members and the constructor parameters when they have the same names.

---

## Key Takeaway

> **Parameterized Constructor = Constructor that receives arguments to initialize an object with specific values.**

```text
Arguments
    ↓
Parameterized Constructor
    ↓
Object initialized with those values
```
