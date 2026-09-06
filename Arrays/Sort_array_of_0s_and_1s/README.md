# Sort 0s and 1s

## Problem Statement

Given an array containing only `0`s and `1`s, sort the array in ascending order **without using the built-in sorting function**.

The sorting must be done **in-place**, meaning we should modify the given array directly without using another array.

### Example

```text
Input:
[0, 1, 0, 1, 0, 1]

Output:
[0, 0, 0, 1, 1, 1]
```

---

# Understand the Problem

We have an array containing only two values:

```text
0 and 1
```

We need to arrange them so that:

```text
All 0s → All 1s
```

For example:

```text
0 1 0 1 0 1
↓
0 0 0 1 1 1
```

### Conditions

* Array contains only `0` and `1`.
* Sort in ascending order.
* Do not use `sort()`.
* Modify the original array.
* Use `O(1)` extra space if possible.

---

# Approach 1: Using `sort()`

### Idea

Use C++'s built-in `sort()` function.

```cpp
void sortUsingSortFun(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}
```

### Complexity

```text
Time  : O(n log n)
Space : Implementation-dependent auxiliary space
```

### Why not use it?

The problem requires us to implement the sorting logic instead of directly using the built-in sorting function.

---

# Approach 2: Counting Method

## Idea

Since the array contains only `0` and `1`, count how many zeros and ones are present.

Then overwrite the array:

```text
First → zeros
Then  → ones
```

### Steps

1. Count the number of `0`s.
2. Count the number of `1`s.
3. Fill the array with all `0`s.
4. Fill the remaining positions with `1`s.

### Code

```cpp
void sortUsingCounting(vector<int>& nums) {
    int zeros = 0;
    int ones = 0;

    int i = 0;

    while(i < nums.size()) {
        if(nums[i] == 0) {
            zeros++;
        } else {
            ones++;
        }

        i++;
    }

    int index = 0;

    while(zeros != 0) {
        nums[index] = 0;
        zeros--;
        index++;
    }

    while(ones != 0) {
        nums[index] = 1;
        ones--;
        index++;
    }
}
```

---

## Working

Suppose:

```text
nums = [0, 1, 0, 1, 0, 1]
```

### Step 1: Count

```text
zeros = 3
ones  = 3
```

### Step 2: Fill zeros

```text
[0, 0, 0, 1, 0, 1]
```

### Step 3: Fill ones

```text
[0, 0, 0, 1, 1, 1]
```

Final answer:

```text
[0, 0, 0, 1, 1, 1]
```

---

# Approach 3: Two Pointer / Partition — Optimal

## Idea

Instead of counting and then rewriting the entire array, we can place every `0` at its correct position while traversing the array.

We use two pointers:

```text
zeroPos → position where the next 0 should be placed
current → element currently being checked
```

### Code

```cpp
void sortZerosAndOnes(vector<int>& nums) {
    int zeroPos = 0;

    for(int current = 0; current < nums.size(); current++) {

        if(nums[current] == 0) {
            swap(nums[zeroPos], nums[current]);
            zeroPos++;
        }
    }
}
```

---

# Working

Consider:

```text
[0, 1, 0, 1, 0, 1]
```

Initially:

```text
zeroPos = 0
current = 0
```

### Current = 0

`nums[current] = 0`

So swap:

```text
swap(nums[0], nums[0])
```

Array:

```text
[0, 1, 0, 1, 0, 1]
```

Move `zeroPos`:

```text
zeroPos = 1
```

---

### Current = 1

```text
nums[1] = 1
```

Nothing to do.

```text
zeroPos = 1
```

---

### Current = 2

```text
nums[2] = 0
```

Swap:

```text
swap(nums[1], nums[2])
```

Array becomes:

```text
[0, 0, 1, 1, 0, 1]
```

Move:

```text
zeroPos = 2
```

---

### Current = 3

```text
nums[3] = 1
```

Nothing to do.

---

### Current = 4

```text
nums[4] = 0
```

Swap:

```text
swap(nums[2], nums[4])
```

Array becomes:

```text
[0, 0, 0, 1, 1, 1]
```

Move:

```text
zeroPos = 3
```

---

### Current = 5

```text
nums[5] = 1
```

Nothing to do.

Final:

```text
[0, 0, 0, 1, 1, 1]
```

---

# Dry Run

### Input

```text
[0, 1, 0, 1, 0, 1]
```

| `current` | `nums[current]` | `zeroPos` | Action  | Array           |
| --------: | --------------: | --------: | ------- | --------------- |
|         0 |               0 |         0 | Swap    | `[0,1,0,1,0,1]` |
|         1 |               1 |         1 | Nothing | `[0,1,0,1,0,1]` |
|         2 |               0 |         1 | Swap    | `[0,0,1,1,0,1]` |
|         3 |               1 |         2 | Nothing | `[0,0,1,1,0,1]` |
|         4 |               0 |         2 | Swap    | `[0,0,0,1,1,1]` |
|         5 |               1 |         3 | Nothing | `[0,0,0,1,1,1]` |

### Output

```text
[0, 0, 0, 1, 1, 1]
```

---

# Complexity Analysis

| Approach    |         Time |                    Space | In-Place |
| ----------- | -----------: | -----------------------: | -------- |
| `sort()`    | `O(n log n)` | Implementation-dependent | Yes      |
| Counting    |       `O(n)` |                   `O(1)` | Yes      |
| Two Pointer |       `O(n)` |                   `O(1)` | Yes      |

The two-pointer approach is optimal in terms of asymptotic complexity:

```text
Time  = O(n)
Space = O(1)
```

We cannot do better than `O(n)` time because we need to inspect the elements of the array.

---

# Mental Model

Think of `zeroPos` as:

> **The position where the next `0` should go.**

And `current` as:

> **The element I am currently checking.**

Whenever:

```text
nums[current] == 0
```

we put that `0` at `zeroPos`:

```cpp
swap(nums[zeroPos], nums[current]);
zeroPos++;
```

So the array gradually becomes:

```text
[ 0 0 0 | remaining elements ]
        ↑
     zeroPos
```

---

# Quick Revision

### Counting

```text
Count 0s → Count 1s → Rewrite array
```

### Two Pointer

```text
Find 0 → Put it at zeroPos → Move zeroPos
```

### Key Pattern

```cpp
if(nums[current] == 0) {
    swap(nums[zeroPos], nums[current]);
    zeroPos++;
}
```

### Final Complexity

```text
O(n) Time
O(1) Space
In-place
```

**Best approach:** Two Pointer / Partition.
