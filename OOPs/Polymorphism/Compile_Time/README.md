# Compile-Time Polymorphism in C++

## Overview

**Compile-Time Polymorphism** means the compiler determines which function or operator to use **at compile time**.

This example demonstrates two forms:

1. **Function Overloading**
2. **Operator Overloading**

---

## 1. Function Overloading

Function overloading allows multiple functions to have the **same name** but different parameter lists.

In this example, `add()` is overloaded with different numbers and types of parameters:

```cpp
int add(int a, int b);

int add(int a, int b, int c);

double add(double a, double b);

double add(double a, double b, double c);
```

### Example

```cpp
Add add1;

add1.add(2, 3);
add1.add(2, 3, 5);
add1.add(2.2, 3.0);
add1.add(2.2, 3.0, 5.5);
```

The compiler selects the appropriate `add()` function based on the arguments.

```text
add(2, 3)
    ↓
add(int, int)

add(2, 3, 5)
    ↓
add(int, int, int)

add(2.2, 3.0)
    ↓
add(double, double)
```

---

## 2. Operator Overloading

**Operator Overloading** allows an existing operator to work with user-defined objects.

In this example, the `+` operator is overloaded for the `Complex` class.

Normally:

```cpp
int a = 2;
int b = 3;

a + b;
```

But after overloading, we can perform:

```cpp
Complex A(2, 5);
Complex B(4, 3);

Complex C = A + B;
```

The expression:

```cpp
A + B
```

is treated as:

```cpp
A.operator+(B);
```

The overloaded operator adds the real and imaginary parts:

```text
A = 2 + 5i
B = 4 + 3i
────────────
C = 6 + 8i
```

---

## Compile-Time Polymorphism

```text
              Compile-Time Polymorphism
                       |
              ┌────────┴────────┐
              ↓                 ↓
     Function Overloading   Operator Overloading
              ↓                 ↓
          Same name          Existing operator
       Different parameters   Custom behavior
```

---

## Key Takeaway

> **Compile-Time Polymorphism allows the compiler to determine the appropriate function or operator during compilation.**

This example demonstrates:

```text
Function Overloading
        +
Operator Overloading
        ↓
Compile-Time Polymorphism
```
