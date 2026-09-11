# Stack Using Linked List

## Introduction

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

The element that is inserted last is the first element to be removed.

### Example

If we insert:

```text
10 → 20 → 30
```

Then:

```text
30 ← removed first
20
10
```

In this implementation, we build a Stack using a **Singly Linked List**.

---

#  Why Use a Linked List for Stack?

A Stack can be implemented using:

* Array
* Vector
* Linked List
* Queue

When using an array, the stack usually has a **fixed capacity**.

With a linked list, nodes are created dynamically using memory allocation.

### Array-Based Stack

```text
Stack
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
                  ↑
                 TOP
```

### Linked List-Based Stack

```text
TOP
 ↓
┌────┬─────┐
│ 50 │  •──┼──→
└────┴─────┘
           ↓
      ┌────┬─────┐
      │ 40 │  •──┼──→
      └────┴─────┘
                 ↓
            ┌────┬─────┐
            │ 30 │  •──┼──→
            └────┴─────┘
                       ↓
                      NULL
```

The `head` pointer represents the **top of the Stack**.

---

# 🔹 LIFO Principle

Stack follows:

> **Last In → First Out**

Suppose we insert:

```text
10
20
30
40
50
```

The stack becomes:

```text
TOP
 ↓
50
40
30
20
10
```

If we perform `remove()`:

```text
50 ← removed
```

The new stack becomes:

```text
TOP
 ↓
40
30
20
10
```

---

# Node Structure

Each linked list node contains two things:

```cpp
class Node{
    public:
    int data;
    Node *next;
};
```

### Visualization

```text
┌───────────┬────────────┐
│   data    │    next    │
└───────────┴────────────┘
```

For example:

```text
┌──────┬──────┐
│  30  │  •───┼──→
└──────┴──────┘
```

* `data` stores the value.
* `next` stores the address of the next node.

---

#  Stack Class

Our Stack class contains three important variables:

```cpp
int size;
Node* head;
int top;
```

### `size`

Stores the maximum capacity of the Stack.

```cpp
StackUsingLinkedList sl(5);
```

This means the Stack can contain a maximum of 5 elements.

---

### `head`

```cpp
Node* head;
```

`head` points to the **top element** of the Stack.

Initially:

```text
head
 ↓
NULL
```

After inserting `10`:

```text
head
 ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```

---

### `top`

```cpp
int top;
```

`top` stores the index of the top element.

Initially:

```text
top = -1
```

After inserting:

```text
10 → top = 0
20 → top = 1
30 → top = 2
```

---

#  Constructor

```cpp
StackUsingLinkedList(int size){
    this->size = size;
    head = NULL;
    top = -1;
}
```

The constructor initializes the Stack.

Initially:

```text
size = 5
top  = -1
head = NULL
```

Which means:

```text
Stack is empty
```

---

#  isEmpty()

The `isEmpty()` function checks whether the Stack contains any elements.

```cpp
bool isEmpty(){
    if(top == -1 || head == NULL){
        return true;
    }

    return false;
}
```

If:

```cpp
top == -1
```

the Stack is empty.

### Initial State

```text
TOP = -1

head
 ↓
NULL
```

Therefore:

```text
isEmpty() → true
```

---

#  Add / Push Operation

The `add()` function inserts a new element at the top of the Stack.

```cpp
void add(int data){
    
    if(top >= size-1){
        cout<<"Stack is Full"<<endl;
        return;
    }

    Node* newNode = new Node(data);

    Node* temp = head;

    newNode->next = temp;
    head = newNode;

    top++;
}
```

This operation is equivalent to the standard Stack operation:

```text
PUSH
```

---

#  How Push Works

Suppose the Stack contains:

```text
TOP
 ↓
30
20
10
NULL
```

Now we want to add:

```text
40
```

### Step 1: Create a new node

```text
newNode
   ↓
┌────┬──────┐
│ 40 │ NULL │
└────┴──────┘
```

### Step 2: Connect new node to current head

```cpp
newNode->next = head;
```

```text
newNode
   ↓
┌────┬─────┐
│ 40 │  •──┼──→ 30
└────┴─────┘
```

### Step 3: Move head

```cpp
head = newNode;
```

Final Stack:

```text
TOP
 ↓
40
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL
```

This is why insertion at the beginning of a linked list is perfect for implementing a Stack.

---
#  Push Dry Run

Initially:

```text
head = NULL
top = -1
```

### `add(10)`

```text
TOP
 ↓
10
 ↓
NULL
```

```text
top = 0
```

---

### `add(20)`

```text
TOP
 ↓
20
 ↓
10
 ↓
NULL
```

```text
top = 1
```

---

### `add(30)`

```text
TOP
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL
```

```text
top = 2
```

---

#  Remove / Pop Operation

The `remove()` function removes the top element.

This operation is equivalent to:

```text
POP
```

Code:

```cpp
void remove(){

    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return;
    }

    Node* temp = head;

    head = temp->next;

    delete temp;

    top--;
}
```

---

#  How Pop Works

Suppose:

```text
TOP
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL
```

We want to remove `30`.

### Step 1: Store the current head

```cpp
Node* temp = head;
```

```text
temp
 ↓
30
 ↓
20
 ↓
10
```

### Step 2: Move head to next node

```cpp
head = temp->next;
```

Now:

```text
head
 ↓
20
 ↓
10
 ↓
NULL
```

### Step 3: Delete old top node

```cpp
delete temp;
```

The node containing `30` is removed from memory.

Final Stack:

```text
TOP
 ↓
20
 ↓
10
 ↓
NULL
```

### Important Pointer Pattern

Remember this pattern:

```cpp
Node* temp = head;
head = head->next;
delete temp;
```

Meaning:

```text
Save old top
      ↓
Move head
      ↓
Delete old top
```

---

#  Print Operation

The `print()` function traverses the linked list and prints all elements.

```cpp
void print(){

    Node* temp = head;

    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}
```

A temporary pointer is used so that the actual `head` does not change.

```text
head
 ↓
50 → 40 → 30 → 20 → 10 → NULL
```

`temp` moves through the list:

```text
temp → 50
temp → 40
temp → 30
temp → 20
temp → 10
temp → NULL
```

---

#  Peek Operation

Your function is named `peak()`:

```cpp
int peak(){
    return head->data;
}
```

The standard Stack terminology is **`peek()`**.

It returns the top element without removing it.

A safer implementation is:

```cpp
int peek(){

    if(isEmpty()){
        cout<<"Stack is empty."<<endl;
        return -1;
    }

    return head->data;
}
```

For:

```text
TOP
 ↓
50
40
30
20
10
```

```cpp
peek()
```

returns:

```text
50
```

The Stack remains unchanged.

---

#  Stack Overflow

Overflow occurs when we try to insert an element into a full Stack.

For a Stack of size `5`:

```text
10
20
30
40
50
```

The Stack is full.

Trying:

```cpp
add(60);
```

produces:

```text
Stack is Full
```

The condition is:

```cpp
if(top >= size - 1)
```

For size `5`:

```text
Maximum valid index = 4
```

Therefore:

```text
top >= 4
```

means the Stack is full.

---

#  Stack Underflow

Underflow occurs when we try to remove an element from an empty Stack.

Example:

```text
TOP
 ↓
NULL
```

Calling:

```cpp
remove();
```

produces:

```text
Stack is empty
```

---

#  Complete Flow

Suppose we execute:

```cpp
StackUsingLinkedList sl(5);

sl.add(10);
sl.add(20);
sl.add(30);
sl.add(40);
sl.add(50);
```

The Stack becomes:

```text
TOP
 ↓
50
 ↓
40
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL
```

Then:

```cpp
sl.remove();
```

removes `50`.

Stack:

```text
TOP
 ↓
40
 ↓
30
 ↓
20
 ↓
10
 ↓
NULL
```

Then:

```cpp
sl.peek();
```

returns:

```text
40
```

---

#  Why Insert and Delete at Head?

A Stack requires:

```text
Push → Add at top
Pop  → Remove from top
```

In a linked list, the beginning can be accessed directly using `head`.

Therefore:

```text
Push
  ↓
Insert at head

Pop
  ↓
Delete from head
```

Both operations take:

```text
O(1)
```

time.

---

#  Complexity Analysis

| Operation        | Time Complexity |
| ---------------- | --------------: |
| `add()` / Push   |            O(1) |
| `remove()` / Pop |            O(1) |
| `peek()`         |            O(1) |
| `isEmpty()`      |            O(1) |
| `print()`        |            O(n) |

### Space Complexity

For `n` elements:

```text
O(n)
```

because every element requires one dynamically allocated node.

---

#  Array Stack vs Linked List Stack

| Feature           | Array                    | Linked List                                                                 |
| ----------------- | ------------------------ | --------------------------------------------------------------------------- |
| Memory allocation | Fixed/contiguous         | Dynamic                                                                     |
| Size              | Usually fixed            | Dynamic                                                                     |
| Push              | O(1)                     | O(1)                                                                        |
| Pop               | O(1)                     | O(1)                                                                        |
| Memory overhead   | Low                      | Extra pointer per node                                                      |
| Overflow          | When capacity is reached | Only when memory allocation fails, unless an artificial max size is imposed |
| Implementation    | Simpler                  | Pointer-based                                                               |

> **Note:** In your implementation, you have deliberately added a `size` limit, so your linked-list Stack also reports overflow when that limit is reached.

---

#  Applications of Stack

Stacks are widely used in computer science.

### 1. Function Calls

The call stack stores function calls.

```text
main()
 ↓
functionA()
 ↓
functionB()
```

---

### 2. Recursion

Recursive function calls use the Stack internally.

---

### 3. Undo / Redo

Applications can maintain previous operations using Stacks.

---

### 4. Browser History

Recently visited pages can be managed using Stack-like behavior.

---

### 5. Expression Evaluation

Stacks are used for:

* Infix expressions
* Prefix expressions
* Postfix expressions

---

### 6. Parentheses Matching

For example:

```text
{ [ ( ) ] }
```

A Stack can be used to verify whether brackets are correctly balanced.

---

#  Important Interview Questions

### Beginner

1. What is a Stack?
2. What does LIFO mean?
3. What are the basic operations of a Stack?
4. What is Stack Overflow?
5. What is Stack Underflow?
6. How do you implement a Stack using a linked list?
7. Why is `head` used as the top of the Stack?

### Intermediate

8. What is the time complexity of Push in a linked-list Stack?
9. What is the time complexity of Pop?
10. Why should insertion and deletion happen at the head?
11. What happens to memory when a node is popped?
12. Why do we use `delete temp`?
13. What is the difference between Stack implementation using an array and a linked list?

### Important Pointer Question

Consider:

```cpp
Node* temp = head;
head = head->next;
delete temp;
```

**Why can't we simply do:**

```cpp
head = head->next;
```

Because the old head node would no longer be reachable, but its dynamically allocated memory would not be released.

That causes a **memory leak**.

---

#  Key Mental Model

Remember the Stack using Linked List like this:

```text
             TOP
              ↓
        ┌───────────┐
        │    50     │
        │   next ───┼────┐
        └───────────┘    ↓
                     ┌───────────┐
                     │    40     │
                     │   next ───┼────┐
                     └───────────┘    ↓
                                  ┌───────────┐
                                  │    30     │
                                  │   next ───┼──→ NULL
                                  └───────────┘
```

### Push

```text
Create Node
     ↓
Connect to head
     ↓
Move head
     ↓
top++
```

### Pop

```text
Save head
     ↓
Move head to next
     ↓
Delete old head
     ↓
top--
```

### Peek

```text
Return head->data
```

---

#  Final Takeaways

* Stack follows **LIFO**.
* In a linked-list Stack, `head` represents the **top**.
* Push means inserting a node at the beginning.
* Pop means deleting the node at the beginning.
* Peek returns the top element without removing it.
* Push and Pop are both **O(1)**.
* Dynamic nodes require **O(n)** space.
* Always `delete` dynamically allocated nodes when they are removed.
* The key Pop pattern is:

```cpp
Node* temp = head;
head = head->next;
delete temp;
```

* The standard operation names are:

  * `add()` → `push()`
  * `remove()` → `pop()`
  * `peak()` → `peek()`
