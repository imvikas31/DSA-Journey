# Runtime Polymorphism in C++

## Overview

**Runtime Polymorphism** means that the function to be executed is determined **at runtime** based on the actual object.

It is commonly achieved using:

* Inheritance
* Function Overriding
* Virtual Functions
* Base Class Pointer or Reference

---

## Example

The example uses an `Animal` base class with two derived classes:

```text
              Animal
             /      \
            ↓        ↓
          Dog        Cat
```

Both `Dog` and `Cat` override the `sound()` function.

---

## Virtual Function

The base class declares `sound()` as `virtual`:

```cpp id="q3m9pt"
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};
```

The derived classes override it:

```cpp id="q0wz73"
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

---

## Base Class Pointer

A base class pointer can point to objects of different derived classes:

```cpp id="0q5g3n"
Animal* animal;

animal = &dog;
animal->sound();

animal = &cat;
animal->sound();
```

When:

```cpp id="3h3n2p"
animal = &dog;
```

the actual object is `Dog`, so:

```text
Dog::sound()
```

is called.

When:

```cpp id="f8k2ry"
animal = &cat;
```

the actual object is `Cat`, so:

```text
Cat::sound()
```

is called.

### Output

```text id="r4s7f1"
Dog barks
Cat meows
```

---

## How Runtime Polymorphism Works

```text id="c0p8k3"
Animal* animal
      |
      ├── points to Dog → Dog::sound()
      |
      └── points to Cat → Cat::sound()
```

The **pointer type remains `Animal*`**, but the function executed depends on the **actual object** it points to.

This selection happens at runtime through **dynamic dispatch**.

---

## Key Takeaway

> **Runtime Polymorphism allows a base class pointer/reference to call the overridden function of the actual derived object at runtime.**

```text id="y9c2n7"
Inheritance
     ↓
Function Overriding
     ↓
Virtual Function
     ↓
Base Pointer / Reference
     ↓
Runtime Polymorphism
```
