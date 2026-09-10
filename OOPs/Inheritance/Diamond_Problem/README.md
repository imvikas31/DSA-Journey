# Diamond Problem in C++

## Overview

The **Diamond Problem** occurs in multiple inheritance when two intermediate classes inherit from the same base class, and another class inherits from both intermediate classes.

### Structure

```text
                  People
                 /      \
                ↓        ↓
            Teacher   Researcher
                \        /
                 \      /
                  ↓    ↓
                Professor
```

`Professor` has **two paths** to `People`:

```text
Professor → Teacher → People

Professor → Researcher → People
```

This can result in **ambiguity** when accessing members of `People`.

---

# The Problem

Consider:

```cpp
class People {
public:
    void walk() {
        cout << "People walks" << endl;
    }
};

class Teacher : public People {
};

class Researcher : public People {
};

class Professor : public Teacher, public Researcher {
};
```

Now:

```cpp
Professor P1;

P1.walk();   // Error: Ambiguous
```

The compiler cannot determine whether `walk()` should be accessed through:

```text
Professor → Teacher → People
```

or:

```text
Professor → Researcher → People
```

The reason is that `Professor` contains two separate `People` base-class subobjects.

```text
Professor
├── Teacher
│   └── People
│
└── Researcher
    └── People
```

---

# Resolution 1: Scope Resolution

One way to resolve the ambiguity is to explicitly specify the inheritance path.

```cpp
Professor P1;

P1.Teacher::walk();
P1.Researcher::walk();
```

### Teacher Path

```text
P1.Teacher::walk()
        ↓
Professor
   ↓
Teacher
   ↓
People
   ↓
walk()
```

### Researcher Path

```text
P1.Researcher::walk()
        ↓
Professor
   ↓
Researcher
   ↓
People
   ↓
walk()
```

This tells the compiler exactly which `walk()` function should be called.

### Important Point

Scope resolution **removes the ambiguity**, but it does **not remove the duplicate `People` objects**.

```text
Professor
├── Teacher → People
└── Researcher → People

      2 People objects
```

---

# Resolution 2: Virtual Inheritance

A proper structural solution is **virtual inheritance**.

```cpp
class VirtualTeacher : virtual public People {
};

class VirtualResearcher : virtual public People {
};

class VirtualProfessor : public VirtualTeacher, public VirtualResearcher {
};
```

Now the common `People` base is shared.

```text
             VirtualProfessor
               /          \
              ↓            ↓
      VirtualTeacher   VirtualResearcher
              \            /
               \          /
                  People
```

There is only **one `People` base-class subobject**.

Therefore:

```cpp
VirtualProfessor P2;

P2.walk();
```

is no longer ambiguous.

---

# Scope Resolution vs Virtual Inheritance

| Technique           | Purpose                                        |
| ------------------- | ---------------------------------------------- |
| Scope Resolution    | Explicitly selects an inheritance path         |
| Virtual Inheritance | Creates one shared common base-class subobject |
| Scope Resolution    | Keeps two `People` objects                     |
| Virtual Inheritance | Removes duplicate `People` base objects        |

---

# Complete Example

```cpp
#include <bits/stdc++.h>
using namespace std;

class People {
public:

    void walk() {
        cout << "People walks" << endl;
    }
};


// -------------------------------
// Normal Inheritance
// -------------------------------

class Teacher : public People {
};

class Researcher : public People {
};

class Professor : public Teacher, public Researcher {
};


// -------------------------------
// Virtual Inheritance
// -------------------------------

class VirtualTeacher : virtual public People {
};

class VirtualResearcher : virtual public People {
};

class VirtualProfessor : public VirtualTeacher, public VirtualResearcher {
};


int main() {

    // --------------------------------
    // Resolution using Scope Resolution
    // --------------------------------

    Professor P1;

    // Explicitly select Teacher → People path.
    P1.Teacher::walk();

    // Explicitly select Researcher → People path.
    P1.Researcher::walk();


    // --------------------------------
    // Resolution using Virtual Inheritance
    // --------------------------------

    VirtualProfessor P2;

    // Only one People base exists.
    // Therefore, there is no ambiguity.
    P2.walk();


    return 0;
}
```

---

# Key Takeaways

* The **Diamond Problem** is caused by multiple inheritance creating **multiple paths to the same base class**.
* In this example, `Professor` gets two `People` subobjects.
* `P1.walk()` becomes ambiguous.
* **Scope resolution** explicitly selects the required path.
* **Virtual inheritance** ensures that only one shared `People` base exists.
* **Virtual inheritance** is different from a **virtual function**; virtual functions are related to runtime polymorphism.

### Remember

```text
Diamond Problem
      ↓
Multiple paths to same base
      ↓
Duplicate base objects
      ↓
Ambiguity
      ↓
Scope Resolution → Select a path
Virtual Inheritance → One shared base
```
