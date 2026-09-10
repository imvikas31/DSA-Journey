# Multilevel Inheritance in C++

## Overview

**Multilevel Inheritance** occurs when a class inherits from another derived class, forming an **inheritance chain**.

In this example:

```text
Animal
   |
   ↓
Mammal
   |
   ↓
Dog
```

* `Animal` → Base class
* `Mammal` → Intermediate class
* `Dog` → Derived class

`Mammal` inherits from `Animal`, and `Dog` inherits from `Mammal`.

---

## Example

```cpp
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "This mammal walks." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "This dog barks." << endl;
    }
};
```

The inheritance chain is:

```text
Animal
  ↓
Mammal
  ↓
Dog
```

---

## Accessing Inherited Methods

A `Dog` object can access methods from all levels of the inheritance chain:

```cpp
Dog dog;

dog.eat();   // From Animal
dog.walk();  // From Mammal
dog.bark();  // From Dog
```

Output:

```text
This animal eats food.
This mammal walks.
This dog barks.
```

`Dog` **directly inherits** from `Mammal` and **indirectly inherits** the functionality of `Animal`.

---

## Key Point

> **Multilevel Inheritance = inheritance through multiple levels, forming a chain.**

Example:

```text
Base → Intermediate → Derived
```

In this example:

```text
Animal → Mammal → Dog
```
