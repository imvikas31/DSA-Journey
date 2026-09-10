# Hierarchical Inheritance in C++

## Overview

**Hierarchical Inheritance** occurs when **multiple child/derived classes inherit from the same parent/base class**.

In this example:

```text
              Animal
             /      \
            ↓        ↓
          Dog        Cat
```

* `Animal` → Parent/Base class
* `Dog` → Child/Derived class
* `Cat` → Child/Derived class

Both `Dog` and `Cat` inherit from `Animal`.

---

## Example

```cpp
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "This dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "This cat meows." << endl;
    }
};
```

The inheritance structure is:

```text
              Animal
             /      \
            ↓        ↓
          Dog        Cat
```

---

## Accessing Inherited Methods

Both child classes can access the `eat()` method inherited from `Animal`.

```cpp
Dog dog;
Cat cat;

dog.eat();
cat.eat();
```

Each child class can also have its own functionality:

```cpp
dog.bark();
cat.meow();
```

### Output

```text
This animal eats food.
This dog barks.
This animal eats food.
This cat meows.
```

---

## Key Point

> **Hierarchical Inheritance = Multiple child classes inherit from one common parent class.**

Example:

```text
          Parent
             ↓
      ┌──────┴──────┐
      ↓             ↓
   Child 1       Child 2
```

In this example:

```text
Animal → Dog
Animal → Cat
```
