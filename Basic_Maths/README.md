# Problem 1 : Sum of Digits

## Problem

Given an integer `num`, find the **sum of all its digits**.

The number can be **positive, negative, or zero**.

### Example

```text
Input: 12345
Output: 15
```

Because:

```text
1 + 2 + 3 + 4 + 5 = 15
```

For a negative number:

```text
Input: -12345
Output: 15
```

The negative sign is not considered a digit.

---

## What Has to Be Done

We need to:

1. Take an integer as input.
2. Extract each digit from the number.
3. Add each digit to a running sum.
4. Continue until all digits have been processed.
5. Return the final sum.

For example:

```text
num = 1234

1234 % 10 → 4
1234 / 10 → 123

123 % 10 → 3
123 / 10 → 12

12 % 10 → 2
12 / 10 → 1

1 % 10 → 1
1 / 10 → 0
```

Therefore:

```text
sum = 4 + 3 + 2 + 1
    = 10
```

---

# Algorithm

## Approach 1: Iterative

### Steps

1. If the number is negative, convert it to positive.
2. Initialize `sum = 0`.
3. Repeat while `num != 0`:

   * Extract the last digit using `num % 10`.
   * Add the digit to `sum`.
   * Remove the last digit using `num / 10`.
4. Return `sum`.

### Pseudocode

```text
sumOfDigits(num):

    if num < 0:
        num = -num

    sum = 0

    while num != 0:

        digit = num % 10

        sum = sum + digit

        num = num / 10

    return sum
```

### Example

For `num = 5832`:

```text
Initial sum = 0

digit = 2 → sum = 2
digit = 3 → sum = 5
digit = 8 → sum = 13
digit = 5 → sum = 18
```

Answer:

```text
18
```

---

## Approach 2: Recursion

The recursive approach follows the same logic, but instead of using a loop, the function calls itself with the number after removing its last digit.

### Steps

1. Define the base case:

   * If `num == 0`, return the current sum.
2. If the number is negative, convert it to positive.
3. Extract the last digit using `num % 10`.
4. Add the digit to `sum`.
5. Remove the last digit using `num / 10`.
6. Recursively call the function with the remaining number.
7. Return the final sum.

### Pseudocode

```text
sumOfDigits(num, sum):

    if num == 0:
        return sum

    if num < 0:
        num = -num

    digit = num % 10

    sum = sum + digit

    return sumOfDigits(num / 10, sum)
```

### Example

For:

```text
num = 1234
```

Recursive calls:

```text
sumOfDigits(1234, 0)
        ↓
sumOfDigits(123, 4)
        ↓
sumOfDigits(12, 7)
        ↓
sumOfDigits(1, 9)
        ↓
sumOfDigits(0, 10)
```

Base case:

```text
num == 0
```

Return:

```text
10
```

---

# Time Complexity

Let `d` be the **number of digits** in the given number.

Each digit is processed exactly once.

Therefore:

### Iterative

```text
Time Complexity = O(d)
```

### Recursive

```text
Time Complexity = O(d)
```

Since the number of digits is approximately `log₁₀(n)`:

```text
O(d) = O(log n)
```

---

# Space Complexity

### Iterative

Only a few variables are used:

```text
sum
digit
num
```

No additional data structure is required.

```text
Space Complexity = O(1)
```

### Recursive

Every recursive call is stored in the **call stack**.

If there are `d` digits, there can be approximately `d` recursive calls.

Therefore:

```text
Space Complexity = O(d)
```

or:

```text
Space Complexity = O(log n)
```

---

# Complexity Comparison

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------: | ---------------: |
| Iterative |            O(d) |             O(1) |
| Recursive |            O(d) |             O(d) |

Where:

```text
d = number of digits in the number
```

---

# Key Concepts Used

* Modulo operator `%`
* Integer division `/`
* Iteration
* Recursion
* Base case
* Call stack
* Handling negative integers

### Important Operations

```cpp
num % 10
```

Extracts the **last digit**.

```cpp
num / 10
```

Removes the **last digit**.

For example:

```text
12345 % 10 = 5
12345 / 10 = 1234
```

These two operations form the core of the solution.

# Problem 2: Smallest Digit in a Number

## Problem

Given an integer `num`, find the **smallest digit** present in the number.

The number can be **positive or negative**. The negative sign (`-`) is not considered a digit.

### Example

```text
Input: 583214
Output: 1
```

The digits are:

```text
5, 8, 3, 2, 1, 4
```

The smallest digit is:

```text
1
```

### Negative Number

```text
Input: -583214
Output: 1
```

The negative sign is ignored, so we consider:

```text
5, 8, 3, 2, 1, 4
```

---

# What Has to Be Done

We need to:

1. Take an integer as input.
2. Handle the negative sign if the number is negative.
3. Extract each digit from the number.
4. Compare the current digit with the smallest digit found so far.
5. Keep the smaller value.
6. Continue until all digits have been processed.
7. Return the smallest digit.

---

# Algorithm

## Approach 1: Iterative

### Steps

1. If `num` is negative, convert it to positive.
2. Initialize `smallestDigit` with a large value such as `INT_MAX`.
3. Repeat while `num != 0`:

   * Extract the last digit using `num % 10`.
   * Compare the digit with `smallestDigit`.
   * Store the smaller value.
   * Remove the last digit using `num / 10`.
4. Return `smallestDigit`.

### Pseudocode

```text
smallestDigit(num):

    if num < 0:
        num = -num

    smallest = 9

    while num != 0:

        digit = num % 10

        smallest = min(smallest, digit)

        num = num / 10

    return smallest
```

### Example

For:

```text
num = 583214
```

Process the digits from right to left:

```text
digit = 4 → smallest = 4
digit = 1 → smallest = 1
digit = 2 → smallest = 1
digit = 3 → smallest = 1
digit = 8 → smallest = 1
digit = 5 → smallest = 1
```

Therefore:

```text
Answer = 1
```

---

# Approach 2: Recursion

The recursive approach performs the same operations as the iterative approach, but uses **recursive function calls instead of a loop**.

### Steps

1. If `num` is negative, convert it to positive.
2. Define the base case:

   * If `num == 0`, return the smallest digit found so far.
3. Extract the last digit using `num % 10`.
4. Compare the digit with `smallestDigit`.
5. Store the smaller value.
6. Remove the last digit using `num / 10`.
7. Recursively process the remaining number.
8. Return the smallest digit.

### Pseudocode

```text
smallestDigitUsingRec(num, smallest):

    if num < 0:
        num = -num

    if num == 0:
        return smallest

    digit = num % 10

    smallest = min(smallest, digit)

    return smallestDigitUsingRec(num / 10, smallest)
```

### Example

For:

```text
num = 5832
```

Recursive calls:

```text
smallestDigitUsingRec(5832)
        ↓
digit = 2
smallest = 2

smallestDigitUsingRec(583)
        ↓
digit = 3
smallest = 2

smallestDigitUsingRec(58)
        ↓
digit = 8
smallest = 2

smallestDigitUsingRec(5)
        ↓
digit = 5
smallest = 2

smallestDigitUsingRec(0)
        ↓
return 2
```

Answer:

```text
2
```

---

# Key Operations

### Extract the Last Digit

```cpp
digit = num % 10;
```

The modulo operator `%` gives the last digit.

Example:

```text
5832 % 10 = 2
```

---

### Remove the Last Digit

```cpp
num = num / 10;
```

Integer division removes the last digit.

Example:

```text
5832 / 10 = 583
```

---

### Find the Minimum

```cpp
smallestDigit = min(digit, smallestDigit);
```

This keeps the smallest digit found so far.

---

# Time Complexity

Let `d` be the **number of digits** in the given number.

Each digit is processed exactly once.

### Iterative Approach

```text
Time Complexity = O(d)
```

### Recursive Approach

```text
Time Complexity = O(d)
```

Since the number of digits is approximately `log₁₀(n)`:

```text
O(d) = O(log n)
```

---

# Space Complexity

### Iterative Approach

Only a constant number of variables are used:

```text
num
digit
smallestDigit
```

Therefore:

```text
Space Complexity = O(1)
```

---

### Recursive Approach

Each recursive call creates a new stack frame.

If the number contains `d` digits, there can be approximately `d` recursive calls.

Therefore:

```text
Space Complexity = O(d)
```

or:

```text
Space Complexity = O(log n)
```

---

# Complexity Comparison

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------: | ---------------: |
| Iterative |            O(d) |             O(1) |
| Recursive |            O(d) |             O(d) |

Where:

```text
d = number of digits
```

---

# Edge Cases

### 1. Single Digit

```text
Input: 7
Output: 7
```

### 2. Number Contains Zero

```text
Input: 58302
Output: 0
```

Once `0` is found, it is the smallest possible digit.

### 3. Negative Number

```text
Input: -583214
Output: 1
```

The negative sign is ignored.

### 4. Zero

```text
Input: 0
Output: 0
```

`0` itself is a digit, so the smallest digit is `0`.

---

# Key Concepts Used

* Modulo operator `%`
* Integer division `/`
* Iteration
* Recursion
* Base case
* Minimum comparison
* Call stack
* Handling negative integers
* Digit extraction


# Problem 3: Reverse a Number

## Problem

Given an integer `num`, reverse its digits.

### Example

```text
Input: 12345
Output: 54321

Input: 1200
Output: 21
```

## Approach 1: Iterative

### Logic

```cpp
digit = num % 10;
rev = rev * 10 + digit;
num = num / 10;
```

### Code

```cpp
int reverseNum(int num) {
    int rev = 0;

    while (num != 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    }

    return rev;
}
```

**Time:** `O(d)`
**Space:** `O(1)`

---

## Approach 2: Recursive

### Logic

Extract the last digit, add it to `rev`, remove the digit, and recursively process the remaining number.

### Code

```cpp
int reverseNumRec(int num, int &rev) {
    if (num == 0) {
        return rev;
    }

    int digit = num % 10;
    rev = rev * 10 + digit;

    return reverseNumRec(num / 10, rev);
}
```

**Time:** `O(d)`
**Space:** `O(d)`

---

## Complexity

| Approach  | Time | Space |
| --------- | ---: | ----: |
| Iterative | O(d) |  O(1) |
| Recursive | O(d) |  O(d) |

`d` = number of digits.

## Key Pattern

```cpp
int digit = num % 10;
rev = rev * 10 + digit;
num = num / 10;
```

**Extract → Add → Remove → Repeat**

## Edge Cases

* `0` → `0`
* Single digit → same number
* `1200` → `21`
* Negative numbers → handle if required
* Check integer overflow for large inputs
