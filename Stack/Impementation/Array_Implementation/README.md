# Stack Data Structure

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

This means:

> The element inserted last will be removed first.

A common real-world example is a **stack of plates**. We add and remove plates only from the top.

---

## 1. Stack Visualization

Suppose we insert:

```text
10
20
30
40
50
```

The stack looks like:

```text
        ┌───────┐
        │  50   │ ← TOP
        ├───────┤
        │  40   │
        ├───────┤
        │  30   │
        ├───────┤
        │  20   │
        ├───────┤
        │  10   │
        └───────┘
```

If we perform `remove()`:

```text
50
```

will be removed first.

The stack becomes:

```text
        ┌───────┐
        │  40   │ ← TOP
        ├───────┤
        │  30   │
        ├───────┤
        │  20   │
        ├───────┤
        │  10   │
        └───────┘
```

This is **LIFO**.

---

# 2. Important Stack Operations

A stack generally supports these operations:

| Operation | Meaning                      | Time |
| --------- | ---------------------------- | ---- |
| Push      | Add an element               | O(1) |
| Pop       | Remove top element           | O(1) |
| Peek      | Get top element              | O(1) |
| isEmpty   | Check whether stack is empty | O(1) |

In this implementation:

```cpp
add()
```

works as **Push**.

```cpp
remove()
```

works as **Pop**.

```cpp
peek()
```

returns the top element.

---

# 3. Stack Using Array

A stack can be implemented using an array.

For example, if the capacity is `5`:

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │    │    │    │    │    │
        └────┴────┴────┴────┴────┘
```

We maintain a variable:

```cpp
int top;
```

which stores the **index of the current top element**.

Initially:

```cpp
top = -1;
```

because the stack is empty.

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │    │    │    │    │    │
        └────┴────┴────┴────┴────┘

top = -1
```

---

# 4. Class Members

Our Stack class contains:

```cpp
class Stack{
public:
    int size;
    int top;
    int *arr;
};
```

### `size`

```cpp
int size;
```

Stores the maximum capacity of the stack.

For:

```cpp
Stack st(5);
```

we have:

```text
size = 5
```

---

### `top`

```cpp
int top;
```

Stores the index of the top element.

Initially:

```text
top = -1
```

After inserting the first element:

```text
top = 0
```

After inserting the second:

```text
top = 1
```

and so on.

---

### `arr`

```cpp
int *arr;
```

This is a dynamically allocated array used to store stack elements.

Memory is allocated using:

```cpp
arr = new int[size];
```

---

# 5. Constructor

```cpp
Stack(int size){
    this->size = size;
    top = -1;
    arr = new int[size];
}
```

When we write:

```cpp
Stack st(5);
```

the constructor creates a stack with capacity `5`.

Internally:

```text
size = 5
top  = -1

arr
 ↓
┌────┬────┬────┬────┬────┐
│    │    │    │    │    │
└────┴────┴────┴────┴────┘
  0    1    2    3    4
```

The stack is initially empty.

---

# 6. isEmpty()

```cpp
bool isEmpty(){
    return top == -1;
}
```

The stack is empty when:

```cpp
top == -1
```

Example:

```text
top = -1
```

Therefore:

```cpp
isEmpty() → true
```

After inserting an element:

```text
top = 0
```

Therefore:

```cpp
isEmpty() → false
```

---

# 7. Push Operation — `add()`

Our `add()` function performs the Push operation.

```cpp
void add(int data){

    if(top >= size-1){
        cout << "Stack is full..." << endl;
        return;
    }

    top++;
    arr[top] = data;
}
```

The important logic is:

```cpp
top++;
arr[top] = data;
```

---

## Example: `add(10)`

Initially:

```text
top = -1
```

Execute:

```cpp
top++;
```

Now:

```text
top = 0
```

Then:

```cpp
arr[top] = 10;
```

So:

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │    │    │    │    │
        └────┴────┴────┴────┴────┘
          ↑
         top
```

---

## Example: `add(20)`

```cpp
top++;
arr[top] = 20;
```

Now:

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │ 20 │    │    │    │
        └────┴────┴────┴────┴────┘
               ↑
              top
```

---

## Example: `add(30)`

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │    │    │
        └────┴────┴────┴────┴────┘
                    ↑
                   top
```

Therefore:

```text
top = 2
```

---

# 8. Stack Overflow

A stack has limited capacity.

Our stack has:

```cpp
Stack st(5);
```

Therefore, it can store only 5 elements.

After:

```cpp
st.add(10);
st.add(20);
st.add(30);
st.add(40);
st.add(50);
```

the stack is full:

```text
Index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │ 40 │ 50 │
        └────┴────┴────┴────┴────┘
                              ↑
                             top
```

Here:

```text
top = 4
size = 5
```

Now if we execute:

```cpp
st.add(60);
```

there is no available space.

Therefore:

```text
Stack Overflow
```

The code checks this using:

```cpp
if(top >= size-1)
```

For size `5`:

```text
size - 1 = 4
```

So when:

```text
top >= 4
```

the stack is full.

---

# 9. Pop Operation — `remove()`

Our `remove()` function performs the Pop operation.

```cpp
void remove(){

    if(isEmpty()){
        cout << "Stack is empty..." << endl;
        return;
    }

    cout << "Removed " << arr[top] << endl;

    top--;
}
```

The important operation is:

```cpp
top--;
```

---

## Example

Suppose:

```text
Index:    0    1    2
        ┌────┬────┬────┐
        │ 10 │ 20 │ 30 │
        └────┴────┴────┘
                    ↑
                   top
```

Here:

```text
top = 2
```

Perform:

```cpp
remove();
```

The top element is:

```text
30
```

Then:

```cpp
top--;
```

Now:

```text
top = 1
```

Logically, the stack becomes:

```text
        ┌────┐
        │ 20 │ ← TOP
        ├────┤
        │ 10 │
        └────┘
```

Notice that we don't actually need to erase `30` from the array.

We simply move `top`.

This is why Pop is **O(1)**.

---

# 10. Stack Underflow

Suppose:

```text
Stack is empty
```

and we perform:

```cpp
remove();
```

There is no element to remove.

This condition is called:

> **Stack Underflow**

We prevent it using:

```cpp
if(isEmpty()){
    cout << "Stack is empty..." << endl;
    return;
}
```

---

# 11. Peek Operation

`peek()` returns the top element without removing it.

```cpp
int peek(){
    return arr[top];
}
```

Suppose:

```text
        ┌────┐
        │ 50 │ ← TOP
        ├────┤
        │ 40 │
        ├────┤
        │ 30 │
        ├────┤
        │ 20 │
        ├────┤
        │ 10 │
        └────┘
```

Then:

```cpp
st.peek();
```

returns:

```text
50
```

But `50` remains in the stack.

### Important difference

```cpp
peek()
```

➡️ Returns the top element.

```cpp
remove()
```

➡️ Removes the top element.

---

# 12. Important Issue With `peek()`

The current implementation has:

```cpp
int peek(){
    return arr[top];
}
```

There is a potential problem.

If the stack is empty:

```text
top = -1
```

then:

```cpp
arr[-1]
```

is invalid memory access.

A safer implementation would be:

```cpp
int peek(){

    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }

    return arr[top];
}
```

This is an important improvement for production-quality code.

---

# 13. Print Stack

The `print()` function displays elements from **top to bottom**.

```cpp
for(int i = top; i >= 0; i--){
    cout << arr[i] << " ";
}
```

Suppose:

```text
Index:    0    1    2    3
        ┌────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │ 40 │
        └────┴────┴────┴────┘
                         ↑
                        top
```

The loop starts from:

```cpp
i = top
```

and moves toward `0`.

Therefore output is:

```text
40 30 20 10
```

This represents the stack from **Top → Bottom**.

---

# 14. Complete Program

```cpp
#include<bits/stdc++.h>
using namespace std;

// Stack implementation using array
class Stack{
    public:
    int size;       // Maximum capacity of stack
    int top;        // Index of top element
    int *arr;       // Array to store elements

    // Constructor
    Stack(int size){
        this->size = size;
        top = -1;               // Stack is initially empty
        arr = new int[size];    // Allocate array
    }

    // Check if stack is empty
    bool isEmpty(){
        return top == -1;
    }

    // Add element to top of stack (Push)
    void add(int data){

        // Check for stack overflow
        if(top >= size-1){
            cout<<"Stack is full, adding more element will lead to stack overflow."<<endl;
            return;
        }

        top++;
        arr[top] = data;

        cout<<"Added "<<data<<" at index "<<top<<endl;
    }

    // Remove top element from stack (Pop)
    void remove(){

        // Check for stack underflow
        if(isEmpty()){
            cout<<"Stack is empty, removing element further will lead to stack underflow."<<endl;
            return;
        }

        cout<<"Removed "<<arr[top]<<" from index "<<top<<endl;

        top--;
    }

    // Return top element without removing it
    int peek(){
        return arr[top];
    }

    // Print stack from top to bottom
    void print(){

        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack elements are : ";

            // Traverse from top to bottom
            for(int i = top; i >= 0; i--){
                cout<<arr[i]<<" ";
            }

            cout<<endl;
        }
    }
};

int main() {

    // Create stack with capacity 5
    Stack st(5);

    st.print();

    // Push elements
    st.add(10);
    st.add(20);
    st.add(30);
    st.add(40);
    st.add(50);

    // Overflow condition
    st.add(60);
    st.add(70);
    st.add(80);

    st.print();

    // Pop top element
    st.remove();

    st.print();

    // Get top element
    int topElement = st.peek();
    cout<<"Top element is : "<<topElement<<endl;

    return 0;
}
```

---

# 15. Dry Run of `main()`

### Step 1

```cpp
Stack st(5);
```

State:

```text
size = 5
top = -1

Stack:
empty
```

---

### Step 2

```cpp
st.add(10);
```

```text
10 ← TOP
```

---

### Step 3

```cpp
st.add(20);
st.add(30);
st.add(40);
st.add(50);
```

Stack:

```text
        ┌────┐
        │ 50 │ ← TOP
        ├────┤
        │ 40 │
        ├────┤
        │ 30 │
        ├────┤
        │ 20 │
        ├────┤
        │ 10 │
        └────┘
```

Array representation:

```text
index:    0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │ 40 │ 50 │
        └────┴────┴────┴────┴────┘
                              ↑
                             top
```

```text
top = 4
```

---

### Step 4 — Overflow

```cpp
st.add(60);
```

Since:

```text
top = 4
size = 5
```

there is no space.

So:

```text
Stack Overflow
```

`60` is **not inserted**.

The same happens for:

```cpp
st.add(70);
st.add(80);
```

---

### Step 5 — Pop

```cpp
st.remove();
```

Current top:

```text
50
```

So:

```text
50 is removed
```

Now:

```text
        ┌────┐
        │ 40 │ ← TOP
        ├────┤
        │ 30 │
        ├────┤
        │ 20 │
        ├────┤
        │ 10 │
        └────┘
```

And:

```text
top = 3
```

---

### Step 6 — Peek

```cpp
int topElement = st.peek();
```

Current top is:

```text
40
```

Therefore:

```text
Top element is : 40
```

---

# 16. Final State Changes

The entire program can be summarized as:

```text
Initially

top = -1

        EMPTY
```

After adding `10`:

```text
10
↑
TOP
```

After adding `20`:

```text
20 ← TOP
10
```

After adding `30`:

```text
30 ← TOP
20
10
```

After adding `40`:

```text
40 ← TOP
30
20
10
```

After adding `50`:

```text
50 ← TOP
40
30
20
10
```

Attempting `60`, `70`, `80`:

```text
OVERFLOW
```

After `remove()`:

```text
40 ← TOP
30
20
10
```

Finally:

```cpp
peek()
```

returns:

```text
40
```

---

# 17. Complexity Analysis

For an array-based stack:

| Operation        | Time Complexity | Space |
| ---------------- | --------------: | ----: |
| `add()` / Push   |            O(1) |  O(1) |
| `remove()` / Pop |            O(1) |  O(1) |
| `peek()`         |            O(1) |  O(1) |
| `isEmpty()`      |            O(1) |  O(1) |
| `print()`        |            O(n) |  O(1) |

The complete stack requires:

```text
O(n)
```

space because we store `n` elements.

---

# 18. Why Is Push O(1)?

Because we don't traverse the array.

We directly use:

```cpp
top++;
arr[top] = data;
```

Only a constant number of operations are performed.

Therefore:

```text
Push = O(1)
```

---

# 19. Why Is Pop O(1)?

We don't shift elements.

We simply do:

```cpp
top--;
```

Therefore:

```text
Pop = O(1)
```

This is an important property of stacks.

---

# 20. Array Stack vs Linked List Stack

A stack can be implemented using either an array or a linked list.

| Feature        | Array                 | Linked List                   |
| -------------- | --------------------- | ----------------------------- |
| Memory         | Contiguous            | Non-contiguous                |
| Size           | Usually fixed         | Dynamic                       |
| Push           | O(1)                  | O(1)                          |
| Pop            | O(1)                  | O(1)                          |
| Overflow       | When capacity is full | Only when memory is exhausted |
| Extra memory   | Low                   | Pointer overhead              |
| Implementation | Simple                | More complex                  |

---

# 21. Stack Using STL

C++ already provides a Stack implementation:

```cpp
#include <stack>

stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top();

st.pop();
```

Output:

```text
30
```

Common STL functions:

```cpp
st.push(x);      // Push
st.pop();        // Pop
st.top();        // Peek
st.empty();      // Check empty
st.size();       // Number of elements
```

---

# 22. Real-World Applications

Stacks are used in many important areas of computer science.

### Function Calls

The program maintains function calls using a call stack.

### Recursion

Recursive function calls are stored in the call stack.

### Undo / Redo

Editors can use stacks to maintain previous operations.

### Browser History

Back/forward navigation can be modeled using stacks.

### Parentheses Matching

For example:

```text
{ [ ( ) ] }
```

Stacks help determine whether brackets are properly balanced.

### Expression Evaluation

Stacks are used for:

```text
Infix
Prefix
Postfix
```

expressions.

### Monotonic Stack

A major DSA pattern used in:

```text
Next Greater Element
Next Smaller Element
Daily Temperatures
Stock Span
Largest Rectangle in Histogram
```

---

# 23. Important Interview Concepts

Before moving to stack problems, make sure you understand:

* LIFO
* Push
* Pop
* Peek
* `top`
* Stack Overflow
* Stack Underflow
* Array implementation
* Linked-list implementation
* STL `stack`
* Time complexity of stack operations
* Applications of stack
* Recursion and call stack
* Monotonic Stack

---

# 24. Important Interview Questions

### Beginner

1. What is a Stack?
2. What is LIFO?
3. What are the basic operations of Stack?
4. What is Stack Overflow?
5. What is Stack Underflow?
6. What is the time complexity of Push?
7. What is the time complexity of Pop?
8. Difference between `pop()` and `peek()`?

### Implementation

9. Implement Stack using an Array.
10. Implement Stack using a Linked List.
11. Implement two stacks in one array.
12. Implement Stack using Queues.
13. Implement Queue using Stacks.

### Problem Solving

14. Reverse a String using Stack.
15. Check for Balanced Parentheses.
16. Find Next Greater Element.
17. Find Next Smaller Element.
18. Design a Min Stack.
19. Evaluate Postfix Expression.
20. Evaluate Reverse Polish Notation.
21. Daily Temperatures.
22. Stock Span.
23. Largest Rectangle in Histogram.

---

# Key Takeaways

```text
STACK
  │
  ├── LIFO
  │
  ├── Push  → Add element
  │
  ├── Pop   → Remove top
  │
  ├── Peek  → See top
  │
  ├── top   → Index of top element
  │
  ├── Overflow → Stack is full
  │
  ├── Underflow → Stack is empty
  │
  └── Basic operations → O(1)
```

### The most important mental model

Remember just this:

```text
          TOP
           ↓
        ┌─────┐
        │  50 │  ← Last In
        ├─────┤
        │  40 │
        ├─────┤
        │  30 │
        ├─────┤
        │  20 │
        ├─────┤
        │  10 │  ← First In
        └─────┘

        POP → 50
```

**Last In → First Out.**

That single principle explains the entire Stack data structure.
