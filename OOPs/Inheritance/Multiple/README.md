# Multiple Inheritance in C++

## Overview

**Multiple Inheritance** occurs when a class inherits from **more than one direct parent/base class**.

In this example:

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

`Professor` inherits from both:

* `Teacher`
* `Researcher`

Therefore, `Professor` demonstrates **Multiple Inheritance**.

---

## Syntax

The syntax for multiple inheritance is:

```cpp
class Child : public Parent1, public Parent2
{
    // Child class members
};
```

In this example:

```cpp
class Professor : public Teacher, public Researcher
{
};
```

This means `Professor` has two direct base classes:

```text
Professor
   ├── Teacher
   └── Researcher
```

---

# Constructor Calling Order

In inheritance, **base class constructors are called before the derived class constructor**.

In Multiple Inheritance, base classes are constructed in the **order in which they are listed in the inheritance declaration**.

For:

```cpp
class Professor : public Teacher, public Researcher
```

the direct base-class order is:

```text
Teacher → Researcher → Professor
```

However, `Teacher` and `Researcher` both inherit from `People`.

Therefore, when creating:

```cpp
Professor P1;
```

the actual constructor order is:

```text
People
  ↓
Teacher
  ↓
People
  ↓
Researcher
  ↓
Professor
```

There are two `People` constructor calls because `Teacher` and `Researcher` each contain their own `People` base subobject.

### Output

```text
People class constructor called
Teacher class constructor called
People class constructor called
Researcher class constructor called
Professor class constructor called
```

### Important Rule

> **In Multiple Inheritance, base classes are constructed from left to right according to their order in the inheritance list.**

For:

```cpp
class Professor : public Teacher, public Researcher
```

the order is:

```text
Teacher → Researcher → Professor
```

---

# Diamond Problem

The inheritance structure in this example also creates a **Diamond Problem**.

### What is the Diamond Problem?

The Diamond Problem occurs when:

1. A base class is inherited by two intermediate classes.
2. A final derived class inherits from both of those intermediate classes.

In this example:

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

The shape forms a diamond, hence the name **Diamond Problem**.

---

## Cause of the Diamond Problem

Both `Teacher` and `Researcher` inherit from `People`:

```cpp
class Teacher : public People
{
};

class Researcher : public People
{
};
```

Then `Professor` inherits from both:

```cpp
class Professor : public Teacher, public Researcher
{
};
```

As a result, `Professor` contains **two separate `People` base subobjects**:

```text
Professor
├── Teacher
│   └── People
│
└── Researcher
    └── People
```

Therefore, if `People` has a method such as:

```cpp
void walk();
```

then:

```cpp
Professor P1;

P1.walk();
```

becomes **ambiguous**.

The compiler cannot determine whether `walk()` should be accessed through:

```text
Professor → Teacher → People
```

or:

```text
Professor → Researcher → People
```

### In short

> **The Diamond Problem is caused by multiple inheritance creating multiple paths to the same base class, resulting in duplicate base-class subobjects and ambiguity when accessing their members.**

The solution to this problem can be covered separately under **Virtual Inheritance**.

---

# Destruction Order

Destruction occurs in the **reverse order of construction**.

If construction is:

```text
People
↓
Teacher
↓
People
↓
Researcher
↓
Professor
```

then destruction happens in reverse:

```text
Professor
↓
Researcher
↓
People
↓
Teacher
↓
People
```

### Core Rule

> **Construct base classes first and derived classes last; destroy derived classes first and base classes last.**

---

# Key Takeaways

* **Multiple Inheritance** → One class inherits from multiple direct base classes.
* `Professor` inherits from both `Teacher` and `Researcher`.
* Base constructors execute before derived constructors.
* Multiple base classes are constructed according to their order in the inheritance list.
* The **Diamond Problem** occurs when multiple inheritance creates multiple paths to the same base class.
* In this example, `Professor` contains two `People` subobjects, which can cause ambiguity.
