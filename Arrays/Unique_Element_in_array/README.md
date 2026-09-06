# Find Unique Element

## Problem

Given an array where **every element appears exactly twice except one element**, find the element that appears only once.

### Example

```text
Input:
[2, 3, 5, 4, 2, 3, 4]

Output:
5
```

---

# Approach 1: Brute Force

### Idea

For every element:

1. Take the current element.
2. Compare it with all elements to its right.
3. Count how many times it occurs.
4. If its count is `1`, return that element.

### Code

```cpp
int findUnique(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }

        if(count == 1) {
            return nums[i];
        }
    }

    return -1;
}
```

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)`

### Why `O(n²)`?

There are two nested loops:

```text
for i → n elements
    for j → remaining elements
```

In the worst case, we compare approximately:

```text
n + (n-1) + (n-2) + ... + 1
```

which results in:

```text
O(n²)
```

---

# Approach 2: Hash Map

### Idea

Store the frequency of every element using `unordered_map`.

For:

```text
[2, 3, 5, 4, 2, 3, 4]
```

The frequency table becomes:

```text
2 → 2
3 → 2
4 → 2
5 → 1
```

The element whose frequency is `1` is the unique element.

### Code

```cpp
int findUniqueUsingMap(vector<int>& nums) {
    unordered_map<int, int> freq;

    for(int num : nums) {
        freq[num]++;
    }

    for(auto& it : freq) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
}
```

### Complexity

* **Time:** `O(n)` average
* **Space:** `O(n)`

The extra space is required to store the frequency of elements.

---

# Approach 3: XOR — Optimal

## Key Idea

Use the XOR (`^`) bitwise operator.

Important XOR properties:

```text
x ^ x = 0
x ^ 0 = x
```

Therefore, when every duplicate appears twice, the two equal values cancel each other.

### Example

```text
2 ^ 3 ^ 5 ^ 4 ^ 2 ^ 3 ^ 4
```

Group the duplicate values:

```text
(2 ^ 2) ^ (3 ^ 3) ^ (4 ^ 4) ^ 5
```

Since:

```text
2 ^ 2 = 0
3 ^ 3 = 0
4 ^ 4 = 0
```

we get:

```text
0 ^ 0 ^ 0 ^ 5
```

Therefore:

```text
5
```

### Code

```cpp
int findUniqueUsingXOR(vector<int>& nums) {
    int ans = 0;

    for(int num : nums) {
        ans ^= num;
    }

    return ans;
}
```

### Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

---

# XOR Dry Run

For:

```text
[2, 3, 5, 4, 2, 3, 4]
```

Start:

```text
ans = 0
```

Process every element:

```text
0 ^ 2 = 2
2 ^ 3 = 1
1 ^ 5 = 4
4 ^ 4 = 0
0 ^ 2 = 2
2 ^ 3 = 1
1 ^ 4 = 5
```

Final:

```text
ans = 5
```

---

# Complexity Comparison

| Approach    |           Time |  Space | Technique          |
| ----------- | -------------: | -----: | ------------------ |
| Brute Force |        `O(n²)` | `O(1)` | Nested loops       |
| Hash Map    | `O(n)` average | `O(n)` | Frequency counting |
| XOR         |         `O(n)` | `O(1)` | Bitwise XOR        |

### Complexity Growth

```text
Operations
   ↑
   │                         O(n²)
   │                       /
   │                     /
   │                   /
   │                 /
   │        O(n log n)
   │             /
   │           /
   │         O(n)
   │       /
   │     /
   │   O(log n)
   │  /
   │ O(1)
   └────────────────────────→ Input Size (n)
```

The important takeaway:

```text
Brute Force → O(n²)
       ↓
Hash Map    → O(n)
       ↓
XOR         → O(n) time + O(1) space
```

---

# Why XOR Is Optimal

When the condition is:

> Every element appears exactly twice except one.

XOR is ideal because:

```text
Duplicate pair → cancels to 0
Unique element → remains
```

And we don't need an additional data structure.

Therefore:

```text
Time  = O(n)
Space = O(1)
```

---

# Important Condition

The XOR approach works when:

```text
Every element appears exactly twice
except one element.
```

For example:

```text
[2, 3, 5, 4, 2, 3, 4]
```

Works → `5`

But if the frequency pattern is different, XOR may not solve the problem.

---

# Mental Model

### Brute Force

```text
Pick → Compare → Count → Find count 1
```

### Hash Map

```text
Store → Count → Find frequency 1
```

### XOR

```text
XOR everything
     ↓
Duplicate pairs cancel
     ↓
Unique element remains
```

## Quick Revision

Remember:

```text
x ^ x = 0
x ^ 0 = x
```

So:

```text
a ^ b ^ c ^ a ^ b
```

becomes:

```text
(a ^ a) ^ (b ^ b) ^ c
= 0 ^ 0 ^ c
= c
```

**Pattern to recognize in interviews:**

> "Every element appears twice except one."

Immediately think:

```text
XOR
```
