# Stack Implementation Using Queue

A **Stack** follows the **LIFO (Last In, First Out)** principle, while a **Queue** follows the **FIFO (First In, First Out)** principle.

This implementation demonstrates how we can build a **Stack using a single Queue** by rearranging the elements after every insertion.

---

## 1. Problem Statement

We want to implement Stack operations:

```text
Push
Pop
Peek
isEmpty
```

using only a:

```cpp
queue<int>
```

The challenge is that Stack and Queue follow opposite ordering principles.

### Stack

```text
LIFO

Last In → First Out
```

### Queue

```text
FIFO

First In → First Out
```

So we need to modify the Queue's order to make it behave like a Stack.

---

# 2. Basic Idea

Suppose we insert:

```text
10
20
30
```

A normal Queue stores them as:

```text
FRONT
  ↓
10 → 20 → 30
```

If we call:

```text
pop()
```

the Queue will remove:

```text
10
```

But Stack requires:

```text
30
```

Therefore, we need to make the newest element appear at the **front** of the Queue.

We transform:

```text
10 → 20 → 30
```

into:

```text
30 → 10 → 20
↑
FRONT
```

Now:

```text
queue.pop()
```

removes:

```text
30
```

which gives us Stack behavior.

---

# 3. Core Strategy

We use **one queue**.

Whenever a new element is added:

1. Store the current number of elements.
2. Add the new element to the queue.
3. Move all previous elements from the front to the back.
4. The newly added element becomes the front element.

The important operation is:

```cpp
q.push(q.front());
q.pop();
```

This moves the front element to the back.

---

# 4. Why Do We Rotate the Queue?

Suppose the current Queue is:

```text
FRONT
  ↓
10 → 20
```

Now we want:

```cpp
add(30);
```

Normally:

```text
10 → 20 → 30
```

But we want the newest element at the front:

```text
30 → 10 → 20
```

So we rotate the existing elements.

### First rotation

Move `10` from front to back:

```text
10 → 20 → 30
```

becomes:

```text
20 → 30 → 10
```

### Second rotation

Move `20` from front to back:

```text
20 → 30 → 10
```

becomes:

```text
30 → 10 → 20
```

Now `30` is at the front.

Therefore:

```text
Stack top = Queue front
```

---

# 5. Class Structure

```cpp
class StackUsingQueue{
public:
    queue<int> q;
    int size;
    int top;
};
```

### `q`

```cpp
queue<int> q;
```

The queue stores all stack elements.

---

### `size`

```cpp
int size;
```

Stores the maximum capacity of the stack.

For example:

```cpp
StackUsingQueue sq(5);
```

means the stack can contain a maximum of 5 elements.

---

### `top`

```cpp
int top;
```

Stores the index of the current top element.

Initially:

```cpp
top = -1;
```

which represents an empty stack.

---

# 6. Constructor

```cpp
StackUsingQueue(int size){
    this->size = size;
    top = -1;
}
```

When:

```cpp
StackUsingQueue sq(5);
```

is created:

```text
size = 5
top = -1
queue = empty
```

---

# 7. isEmpty()

```cpp
bool isEmpty(){
    if(top == -1 || q.empty()){
        return true;
    }
    return false;
}
```

The stack is considered empty when there are no elements.

Initially:

```text
top = -1
q = empty
```

Therefore:

```text
isEmpty() → true
```

After inserting an element:

```text
top = 0
```

and:

```text
q = {element}
```

Therefore:

```text
isEmpty() → false
```

---

# 8. Add / Push Operation

The `add()` function performs the Stack's **Push** operation.

```cpp
void add(int data){

    if(top >= size-1){
        cout<<"Stack full, adding further will lead to overflow"<<endl;
        return;
    }

    top++;
    q.push(data);

    for(int i = 0; i < top; i++){
        q.push(q.front());
        q.pop();
    }
}
```

---

## Step 1 — Check Overflow

```cpp
if(top >= size-1)
```

For a stack of size `5`, valid indexes are:

```text
0  1  2  3  4
```

When:

```text
top = 4
```

the stack is full.

So another insertion would cause:

```text
Stack Overflow
```

---

## Step 2 — Update Top

```cpp
top++;
```

Initially:

```text
top = -1
```

After the first insertion:

```text
top = 0
```

After the second:

```text
top = 1
```

and so on.

---

## Step 3 — Insert Into Queue

```cpp
q.push(data);
```

Suppose:

```cpp
add(30);
```

The queue becomes:

```text
10 → 20 → 30
```

But we need:

```text
30 → 10 → 20
```

---

## Step 4 — Rotate Previous Elements

```cpp
for(int i = 0; i < top; i++){
    q.push(q.front());
    q.pop();
}
```

The loop moves the old elements from the front to the back.

The newly inserted element is therefore moved to the front logically.

---

# 9. Complete Push Dry Run

Let's perform:

```cpp
add(10);
add(20);
add(30);
```

---

### `add(10)`

Initially:

```text
Queue = empty
top = -1
```

After:

```cpp
top++;
q.push(10);
```

we get:

```text
FRONT
  ↓
10
```

```text
top = 0
```

The loop doesn't execute because:

```text
i < top
i < 0
```

---

### `add(20)`

Before:

```text
FRONT
  ↓
10
```

After inserting:

```text
10 → 20
```

`top` becomes:

```text
1
```

Loop executes once.

Move `10` to the back:

```text
20 → 10
```

Now:

```text
FRONT
  ↓
20 → 10
```

---

### `add(30)`

Before:

```text
20 → 10
```

After insertion:

```text
20 → 10 → 30
```

`top` becomes:

```text
2
```

Loop executes twice.

First rotation:

```text
10 → 30 → 20
```

Second rotation:

```text
30 → 20 → 10
```

Final:

```text
FRONT
  ↓
30 → 20 → 10
```

This now behaves exactly like a Stack.

---

# 10. Pop Operation

The `pop()` function removes the top element.

```cpp
void pop(){
    if(isEmpty()){
        cout<<"Stack is empty, removing further will lead to underflow"<<endl;
    }
    else{
        cout<<"Removing "<<q.front()<<" from index "<<top<<endl;
        q.pop();
        top--;
    }
}
```

Because we maintain:

```text
Newest element → FRONT
```

we can simply use:

```cpp
q.pop();
```

---

## Example

Current queue:

```text
FRONT
  ↓
30 → 20 → 10
```

Stack representation:

```text
30 ← TOP
20
10
```

Calling:

```cpp
pop();
```

removes:

```text
30
```

Queue becomes:

```text
20 → 10
```

and:

```cpp
top--;
```

updates the top index.

---

# 11. Stack Underflow

If we call:

```cpp
pop();
```

when the stack is empty, there is nothing to remove.

This is called:

> **Stack Underflow**

The implementation checks:

```cpp
if(isEmpty())
```

before removing an element.

---

# 12. Peek Operation

The `peek()` function returns the top element without removing it.

```cpp
int peek(){
    return q.front();
}
```

Because our implementation always keeps the newest element at the front:

```text
FRONT
  ↓
30 → 20 → 10
```

Therefore:

```cpp
q.front()
```

returns:

```text
30
```

So:

```cpp
peek()
```

returns:

```text
30
```

The element remains in the queue.

---

# 13. Print Operation

The `print()` function displays the stack from top to bottom.

```cpp
queue<int> temp = q;

while(!temp.empty()){
    cout<<temp.front()<<" ";
    temp.pop();
}
```

A copy of the queue is created:

```cpp
queue<int> temp = q;
```

This is important because if we directly used:

```cpp
q.pop();
```

while printing, we would destroy the actual stack.

Instead, we remove elements from:

```cpp
temp
```

and keep:

```cpp
q
```

unchanged.

---

# 14. Why Does One Queue Work?

The key invariant of our implementation is:

> **The newest element is always maintained at the front of the queue.**

For example:

```text
After add(10):

10
↑
FRONT
```

After `add(20)`:

```text
20 → 10
↑
FRONT
```

After `add(30)`:

```text
30 → 20 → 10
↑
FRONT
```

After `add(40)`:

```text
40 → 30 → 20 → 10
↑
FRONT
```

Therefore:

```text
Queue FRONT
     ↓
Stack TOP
```

So:

```cpp
q.pop()
```

can behave as:

```text
Stack.pop()
```

---

# 15. Complexity Analysis

This implementation makes **Push expensive** and keeps **Pop cheap**.

### Push

Suppose there are `n` existing elements.

After inserting the new element, we rotate all `n` old elements.

Therefore:

```text
Push = O(n)
```

---

### Pop

We only perform:

```cpp
q.pop();
```

Therefore:

```text
Pop = O(1)
```

---

### Peek

We directly access:

```cpp
q.front();
```

Therefore:

```text
Peek = O(1)
```

---

### isEmpty

Checking:

```cpp
q.empty();
```

takes:

```text
O(1)
```

---

# 16. Complexity Table

| Operation  | Time Complexity |
| ---------- | --------------: |
| Add / Push |        **O(n)** |
| Pop        |        **O(1)** |
| Peek       |        **O(1)** |
| isEmpty    |        **O(1)** |
| Print      |        **O(n)** |
| Space      |        **O(n)** |

---

# 17. Complete Flow

```text
              STACK USING QUEUE
                      │
                      ▼
               One Queue (q)
                      │
                      ▼
              ┌───────────────┐
              │ Add new item  │
              └───────┬───────┘
                      │
                      ▼
              Put item in queue
                      │
                      ▼
            Move old elements
             front → back
                      │
                      ▼
          New element becomes FRONT
                      │
                      ▼
             FRONT = STACK TOP
                      │
              ┌───────┴───────┐
              ▼               ▼
             pop()           peek()
              │               │
              ▼               ▼
          q.pop()          q.front()
```

---

# 18. Stack vs Queue

| Feature   | Stack   | Queue   |
| --------- | ------- | ------- |
| Principle | LIFO    | FIFO    |
| Insert    | Top     | Rear    |
| Remove    | Top     | Front   |
| View      | Top     | Front   |
| C++ STL   | `stack` | `queue` |

Our goal is:

```text
Queue
FIFO
 ↓
Rearrangement
 ↓
Stack
LIFO
```

---

# 19. One Queue vs Two Queues

There are multiple ways to implement Stack using Queues.

### One Queue — Costly Push

This implementation:

```text
Push → O(n)
Pop  → O(1)
Peek → O(1)
```

### Two Queues — Alternative Approach

Another common implementation uses two queues and can make either Push or Pop expensive depending on the strategy.

The important interview concept is not the exact implementation but understanding the **trade-off**.

---

# 20. Important Interview Questions

### Conceptual

1. How can you implement Stack using Queue?
2. Why is Stack LIFO?
3. Why is Queue FIFO?
4. Why can't we directly use Queue's `pop()` for Stack?
5. Why do we rotate the queue after insertion?
6. Why is Push O(n) in this implementation?
7. Why is Pop O(1)?

### Implementation

8. Implement Stack using one Queue.
9. Implement Stack using two Queues.
10. Implement Queue using two Stacks.
11. Implement Stack without using the STL `stack`.
12. Implement Stack using only Queue operations.

### Advanced

13. Which operation can be made O(1) using one Queue?
14. Compare one-queue and two-queue implementations.
15. What is the space complexity?
16. What happens when the Queue is empty?
17. How would you handle Stack Overflow?

---

# 21. Important Code Pattern

The most important part of this implementation is:

```cpp
top++;
q.push(data);

for(int i = 0; i < top; i++){
    q.push(q.front());
    q.pop();
}
```

Remember the flow:

```text
1. Increase top
       ↓
2. Insert new element
       ↓
3. Rotate old elements
       ↓
4. New element reaches FRONT
       ↓
5. FRONT behaves as STACK TOP
```

---

# 22. Final Mental Model

Don't memorize the complete code.

Remember this picture:

```text
NORMAL QUEUE

FRONT
  ↓
10 → 20 → 30


        PUSH(40)
             ↓

10 → 20 → 30 → 40
             ↓
      Rotate old elements
             ↓

40 → 10 → 20 → 30
↑
FRONT
```

Now:

```text
Queue FRONT
     ↓
Stack TOP
```

Therefore:

```text
Stack.pop()
     ↓
Queue.pop()

Stack.peek()
     ↓
Queue.front()
```

The entire technique is based on maintaining one simple rule:

> **Always keep the most recently inserted element at the front of the queue.**

That converts the Queue's FIFO behavior into the Stack's LIFO behavior.
