# Abstraction Using Abstract Class in C++

## What is Abstraction?

**Abstraction** means hiding implementation details and exposing only the essential functionality.

In this example, the `Animal` class defines that every animal must have a `sound()` function, but it does not define how the sound is produced.

---

## Abstract Class

A class containing at least one **pure virtual function** becomes an **abstract class**.

```cpp
class Animal {
public:
    virtual void sound() = 0;
};
```

Here:

* `Animal` is an abstract class.
* `sound()` is a pure virtual function.
* `= 0` makes the function pure virtual.
* An object of an abstract class cannot be created directly.

```cpp
// Animal a;   // ❌ Not allowed
```

---

## Derived Classes

Derived classes provide the actual implementation of the pure virtual function.

```cpp
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};
```

Both `Dog` and `Cat` follow the contract defined by `Animal`, but each provides its own implementation.

---

## How Abstraction Works

```text
              Animal
         (Abstract Class)
                |
          sound() = 0
          "What to do"
             /    \
            /      \
          Dog      Cat
           |        |
      "How to do" "How to do"
           |        |
       Dog barks  Cat meows
```

The `Animal` class specifies **what functionality is required**, while the derived classes decide **how that functionality is implemented**.

---

## Key Points

* An abstract class cannot be instantiated directly.
* An abstract class contains at least one pure virtual function.
* A pure virtual function is declared using `= 0`.
* Derived classes provide the implementation of pure virtual functions.
* Abstract classes are commonly used to achieve **abstraction** in C++.

### Key Takeaway

> **An abstract class defines what a derived class must do, while the derived class defines how it does it.**
