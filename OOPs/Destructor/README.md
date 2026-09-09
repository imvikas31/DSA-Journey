# Destructor in C++

A **destructor** is a special member function of a class that is automatically called when an object is destroyed.

It is mainly used for **cleanup and releasing resources** held by an object.

---

## 1. Syntax

A destructor has the same name as the class, preceded by `~`.

```cpp
class Student {
public:

    ~Student() {
        cout << "Student destroyed." << endl;
    }
};
```

For a class named:

```cpp
Student
```

the destructor is:

```cpp
~Student()
```

---

## 2. Important Properties of a Destructor

A destructor:

* Has the same name as the class.
* Starts with `~`.
* Has **no return type**.
* Takes **no parameters**.
* Cannot be overloaded.
* Is automatically called when an object's lifetime ends.
* Is mainly used for resource cleanup.

---

# 3. Destructor with a Stack Object

Consider:

```cpp
{
    Student s1("Vikas Singh", 112);

    cout << s1.name << endl;
    cout << s1.id << endl;

}
```

`s1` is a local object.

Its lifetime is limited to the block:

```cpp
{
    // lifetime of s1
}
```

When execution reaches the closing brace:

```cpp
}
```

`s1` goes out of scope.

The destructor is automatically called.

```text
Object created
      ↓
Constructor called
      ↓
Object used
      ↓
Scope ends
      ↓
Destructor called automatically
      ↓
Object destroyed
```

So you do **not** need to write:

```cpp
delete s1;    // ❌
```

for a normal local object.

---

# 4. Destructor with a Heap Object

Consider:

```cpp
Student* s2 = new Student("Saurabh", 113);
```

Here, the `Student` object is dynamically allocated on the heap.

Because it was created using `new`, it should be explicitly released.

```cpp
delete s2;
```

When `delete` is executed:

1. The destructor is called.
2. The object's memory is released.

```text
new Student(...)
       ↓
Constructor
       ↓
Object exists on heap
       ↓
delete s2
       ↓
Destructor
       ↓
Heap memory released
```

---

# 5. Destructor Example

```cpp
#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int id;

    Student(string name, int id) {
        this->name = name;
        this->id = id;

        cout << "Student created." << endl;
    }

    ~Student() {
        cout << "Student destroyed." << endl;
    }
};

int main() {

    {
        Student s1("Vikas Singh", 112);

        cout << "Name of student s1 : "
             << s1.name << endl;

        cout << "ID of student s1 : "
             << s1.id << endl;

    } // Destructor of s1 is automatically called


    Student* s2 = new Student("Saurabh", 113);

    cout << "Name of student s2 : "
         << s2->name << endl;

    cout << "ID of student s2 : "
         << s2->id << endl;


    delete s2;  // Destructor of s2 is called

    return 0;
}
```

---

# 6. `delete` and Destructor

An important point is that:

```cpp
delete s2;
```

does more than simply release memory.

For a class object, the process is conceptually:

```text
delete s2
   │
   ├── Destructor is called
   │
   └── Memory is released
```

So the destructor is responsible for the object's cleanup logic, while `delete` performs destruction and deallocation for a dynamically allocated object.

---

# 7. Dangling Pointer

After:

```cpp
delete s2;
```

the `Student` object no longer exists.

However, the pointer variable `s2` still exists.

It still contains the old memory address.

Therefore, it becomes a **dangling pointer**.

```text
Stack                       Heap

┌─────────────┐             ┌──────────────┐
│ s2          │────────────>│ ❌ Destroyed │
│ old address │             │              │
└─────────────┘             └──────────────┘
       ↑
       │
 Dangling pointer
```

Therefore this is invalid:

```cpp
delete s2;

cout << s2->name;   // ❌ Undefined Behavior
```

The object has already been destroyed.

The program might:

* Print garbage
* Crash
* Appear to work accidentally
* Behave unpredictably

---

# 8. Avoiding a Dangling Pointer

After deleting the object, you can set the pointer to `nullptr`:

```cpp
delete s2;
s2 = nullptr;
```

Now:

```cpp
if (s2 != nullptr) {
    cout << s2->name;
}
```

This makes it clear that `s2` no longer points to a valid object.

---

# 9. `delete` vs `delete[]`

This is an important rule:

```text
new       → delete
new[]     → delete[]
```

For a single object:

```cpp
Student* s = new Student("Saurabh", 113);

delete s;
```

For an array:

```cpp
Student* students = new Student[5];

delete[] students;
```

### Important

If you create:

```cpp
Student* s2 = new Student("Saurabh", 113);
```

you must use:

```cpp
delete s2;
```

**Not:**

```cpp
delete[] s2;    // ❌ Undefined Behavior
```

---

# 10. Destructor vs Constructor

| Constructor                   | Destructor                      |
| ----------------------------- | ------------------------------- |
| Called when object is created | Called when object is destroyed |
| Initializes object            | Cleans up object/resources      |
| Same name as class            | `~ClassName()`                  |
| Can be overloaded             | Cannot be overloaded            |
| Can take parameters           | Takes no parameters             |
| Called during initialization  | Called during destruction       |

Example:

```cpp
Student s1("Vikas Singh", 112);
```

Lifecycle:

```text
Constructor
    ↓
Object exists
    ↓
Object is used
    ↓
Destructor
    ↓
Object destroyed
```

---

# 11. Destructor and Resource Management

Destructors become especially important when a class owns resources such as:

* Dynamically allocated memory
* File handles
* Database connections
* Locks
* Other resources requiring cleanup

Example:

```cpp
class Array {
private:
    int* data;

public:

    Array() {
        data = new int[100];
    }

    ~Array() {
        delete[] data;
    }
};
```

Here:

```cpp
data = new int[100];
```

allocates memory.

The destructor releases it:

```cpp
delete[] data;
```

This helps prevent a **memory leak**.

---

# 12. Important Interview Points

### What is a destructor?

> A destructor is a special member function that is automatically called when an object's lifetime ends and is primarily used for cleanup and resource management.

### When is a destructor called?

For a local object:

```cpp
Student s;
```

It is called automatically when the object goes out of scope.

For a dynamically allocated object:

```cpp
Student* s = new Student();
```

it is called when:

```cpp
delete s;
```

is executed.

### Can a destructor take parameters?

No.

```cpp
~Student(int x);    // ❌
```

### Can a destructor be overloaded?

No.

A class can have only one destructor.

### Does `delete` destroy the pointer?

No.

```cpp
delete s2;
```

destroys the **object pointed to by `s2`** and releases its memory.

The pointer variable itself still exists.

---

# 13. Key Takeaways

```text
Destructor
    ↓
~ClassName()
```

```text
Stack object
    ↓
Scope ends
    ↓
Destructor automatically called
```

```text
Heap object
    ↓
delete pointer
    ↓
Destructor called
    ↓
Memory released
```

```text
delete
    ↓
Pointer still exists
    ↓
But object no longer exists
    ↓
Dangling pointer
```

And the most important memory-management rule:

```text
new       → delete
new[]     → delete[]
```
