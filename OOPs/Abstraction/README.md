# Abstraction and Abstract Class in C++

## What is Abstraction?

**Abstraction** means hiding unnecessary implementation details and exposing only the essential functionality to the user.

For example, an `Animal` class can define that every animal should have a `sound()` function without specifying how each animal makes its sound.

```cpp
class Animal {
public:
    virtual void sound() = 0;
};
```

Here, `Animal` defines **what** functionality is required, while derived classes define **how** that functionality works.

```text
              Animal
        (Abstract Class)
               |
         sound() = 0
        "What to do"
          /       \
         /         \
       Dog         Cat
        |           |
   "How to do" "How to do"
        |           |
   Dog barks    Cat meows
```

---

# Abstract Class

An **abstract class** is a class that cannot be instantiated directly.

In C++, a class becomes abstract when it contains **at least one pure virtual function**.

```cpp
class Animal {
public:
    virtual void sound() = 0;
};
```

Therefore:

```cpp
// Animal a;   // ❌ Cannot create object
```

The abstract class is generally used as a **base class** for derived classes.

---

## What is a Pure Virtual Function?

A **pure virtual function** is a virtual function declared with `= 0`.

```cpp
virtual void sound() = 0;
```

It provides a requirement for derived classes without providing an implementation in the base class.

A class containing at least one pure virtual function becomes an **abstract class**.

### Example

```cpp
class Animal {
public:
    virtual void sound() = 0;
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};
```

`Animal` defines the requirement:

> Every derived animal must provide `sound()`.

`Dog` provides the implementation.

---

# Can an Abstract Class Inherit from Another Abstract Class?

**Yes.**

An abstract class can inherit from another abstract class just like a regular class.

The derived abstract class inherits the pure virtual functions and other members of the base class.

It does **not** have to implement all inherited pure virtual functions if it is intended to remain abstract.

### Example

```cpp
class Animal {
public:
    virtual void sound() = 0;
};

class Mammal : public Animal {
    // sound() is not implemented.
    // Mammal remains abstract.
};
```

The derived abstract class can:

* Implement the inherited pure virtual functions, or
* Leave them unimplemented and remain abstract.

A further derived class can implement the remaining pure virtual functions and become a concrete class.

---

# Can an Abstract Class Have a Constructor?

**Yes.**

An abstract class can have a constructor, but an object of the abstract class cannot be created directly.

```cpp
class Animal {
public:
    Animal() {
        cout << "Animal constructor" << endl;
    }

    virtual void sound() = 0;
};

// Animal a;   // ❌ Cannot create object
```

However, the constructor of the abstract class is called when an object of a derived class is created.

```cpp
class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor" << endl;
    }

    void sound() override {
        cout << "Dog barks" << endl;
    }
};

Dog d;
```

The construction order is:

```text
Dog d
  |
  ↓
Animal constructor
  |
  ↓
Dog constructor
```

This allows the abstract base class to initialize its own data members before the derived class performs its initialization.

### Calling the Base Constructor

A derived class can explicitly invoke the abstract base class constructor using a member initializer list.

```cpp
class Dog : public Animal {
public:
    Dog() : Animal() {
        cout << "Dog constructor" << endl;
    }

    void sound() override {
        cout << "Dog barks" << endl;
    }
};
```

### Key Points

* An abstract class **can have a constructor**.
* An abstract class **cannot be instantiated directly**.
* Its constructor runs when a derived-class object is created.
* A derived constructor can call the base constructor using a member initializer list.

---

# Quick Revision

| Concept                        | Key Point                                                                      |
| ------------------------------ | ------------------------------------------------------------------------------ |
| **Abstraction**                | Hides implementation details and exposes essential functionality               |
| **Abstract Class**             | A class that cannot be instantiated directly                                   |
| **Pure Virtual Function**      | Virtual function declared using `= 0`                                          |
| **Abstract Class Inheritance** | An abstract class can inherit from another abstract class                      |
| **Abstract Class Constructor** | Allowed and called when a derived object is created                            |
| **Concrete Class**             | A class that provides implementations for all inherited pure virtual functions |

## Key Takeaway

> **Abstraction focuses on what an object should do rather than how it does it. In C++, abstract classes and pure virtual functions are a major mechanism for achieving this abstraction.**
