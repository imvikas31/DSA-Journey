# Copy Constructor in C++

## Overview

A **Copy Constructor** is a special constructor used to create a **new object by copying the data of an existing object**.

### Syntax

```cpp
ClassName(const ClassName &object);
```

In this example:

```text
s1 → Existing object
 ↓
Copy Constructor
 ↓
s2 → New copied object
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

    // Copy Constructor
    Student(const Student &s1) {
        this->name = s1.name;
        this->id = s1.id;
    }
};
```

### Creating the Objects

```cpp
Student s1("Vikas Singh", 112);

// Copy constructor is called
Student s2(s1);
```

Here:

* `s1` is the existing object.
* `s2` is the new object.
* `s2` receives copies of `s1`'s data.

Therefore:

```text
s1                     s2
------------------     ------------------
name = Vikas Singh     name = Vikas Singh
id   = 112             id   = 112
```

---

## Key Point

> **Copy Constructor creates a new object by copying an existing object.**

The copy constructor is called when:

```cpp
Student s2(s1);
```

is used.

### Important Syntax

```cpp
Student(const Student &s1)
```

The object is passed by **const reference** to avoid creating another copy while passing it to the copy constructor.
