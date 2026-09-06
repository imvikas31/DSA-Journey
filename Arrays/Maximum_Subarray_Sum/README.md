# Maximum Subarray Sum – Brute Force, Better, and Optimal Approaches

This project solves the classic **Maximum Subarray Sum** problem using three different approaches, progressing from a naive brute-force solution to the optimal Kadane's Algorithm. Each approach is implemented separately to help understand the evolution in optimization.

## 📋 Problem Statement

Given an array of integers, find the **maximum sum of any contiguous subarray**.

**Example:**
Input: {5, 4, -1, 7, 8}
Output: Maximum Subarray sum: 23

---

## 1️⃣ Brute Force Approach (with start/end indices)

### Code Logic

```cpp
int maxSubArraySum(vector<int>&nums,int &i, int &j){
    int n = nums.size();
    int maxSum = INT_MIN;

    for(int start = 0; start < n; start++){
        for(int end = start; end < n; end++){
            int sum = 0;
            for(int k = start; k <= end; k++){
                sum += nums[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
                i = start;
                j = end;
            }
        }
    }
    return maxSum;
}
```

### Steps Involved

1. **Outer loop (`start`)** — Fix the starting index of the subarray, from `0` to `n-1`.
2. **Middle loop (`end`)** — Fix the ending index of the subarray, from `start` to `n-1`. Together, `start` and `end` generate **every possible subarray**.
3. **Inner loop (`k`)** — For each `(start, end)` pair, iterate from `k = start` to `k = end` and accumulate the sum of that subarray into `sum`.
4. **Comparison** — After computing the sum of the current subarray, compare it with `maxSum`. If it's larger, update `maxSum` and also store the current `start` and `end` indices into `i` and `j` (passed by reference), so the caller knows *which* subarray produced the max sum.
5. **Return** — After checking all possible subarrays, return `maxSum`.

### Complexity

| Time | Space |
|------|-------|
| O(n³) | O(1) |

- Two loops generate all `(start, end)` pairs → O(n²)
- One more loop to sum each subarray → O(n)
- Total: **O(n³)**

### Why it's inefficient

For every single subarray, the sum is recalculated from scratch using a fresh inner loop, even though most of the sum was already computed in the previous iteration. This repeated work is what makes this the slowest approach.

---

## 2️⃣ Better Approach (Improved Brute Force)

### Code Logic

```cpp
int maxSubArraySum(vector<int>&nums){
    int n = nums.size();
    int maxSum = INT_MIN;

    for(int val : nums){
        int sum = 0;
        for(int el : nums){
            sum += el;
            maxSum = max(sum,maxSum);
        }
    }
    return maxSum;
}
```

### Steps Involved

1. **Outer loop (`val : nums`)** — Runs `n` times, once for every element in the array (this loop simply acts as a counter to control how many "starting points" get tried — it doesn't directly use `val`).
2. **Inner loop (`el : nums`)** — For each outer iteration, restart `sum = 0` and traverse the array again, accumulating `sum += el` element by element.
3. **Running comparison** — After adding each element, immediately compare `sum` with `maxSum` and update `maxSum = max(sum, maxSum)`. This effectively checks the sum of subarrays starting from index `0` up to every index, across `n` different offset passes.
4. **Return** — After completing all outer iterations, return `maxSum`.

### Complexity

| Time | Space |
|------|-------|
| O(n²) | O(1) |

### Why it's "better" but still not optimal

This eliminates the third (innermost) loop from the brute-force approach by accumulating the sum incrementally (`sum += el`) instead of recomputing it from scratch each time. This drops complexity from O(n³) to O(n²). However, it still doesn't correctly/efficiently track distinct subarrays by explicit start/end indices — it relies on repeated full passes, so there's still redundant work (O(n²) instead of O(n)).

---

## 3️⃣ Optimal Approach — Kadane's Algorithm

### Code Logic

```cpp
int maxSubArraySum(vector<int>&nums){
    int n = nums.size();
    int maxSum = INT_MIN;

    int currSum = 0;
    for(int el : nums){
       currSum += el;
       maxSum = max(currSum,maxSum);

       if(currSum < 0){
        currSum = 0;
       }
    }
    return maxSum;
}
```

### Steps Involved

1. **Initialize** — Set `maxSum = INT_MIN` (to correctly handle arrays with all negative numbers) and `currSum = 0`.
2. **Single pass loop (`el : nums`)** — Traverse the array only once, element by element.
3. **Add to running sum** — `currSum += el` adds the current element to the running subarray sum.
4. **Update global max** — `maxSum = max(currSum, maxSum)` checks if the current running sum is the best one seen so far, and updates `maxSum` if so.
5. **Reset on negative** — If `currSum` drops below `0`, reset it to `0`. This is the key insight: a negative running sum can never help maximize a future subarray sum, so it's better to "restart" the subarray from the next element.
6. **Return** — After the single pass completes, `maxSum` holds the answer.

### Complexity

| Time | Space |
|------|-------|
| O(n) | O(1) |

### Why it's optimal

Kadane's Algorithm makes a single pass through the array and uses the **greedy insight** that any negative running sum should be discarded, since it can only hurt (never help) a future subarray sum. This eliminates all the redundant recomputation from the previous two approaches, achieving linear time.

---

## 📊 Complexity Comparison

| Approach | Time Complexity | Space Complexity | Tracks Indices? |
|----------|------------------|-------------------|------------------|
| Brute Force | O(n³) | O(1) | ✅ Yes (start & end) |
| Better | O(n²) | O(1) | ❌ No |
| Optimal (Kadane's) | O(n) | O(1) | ❌ No (can be extended to track) |

---

## ⚙️ Compilation & Execution

```bash
g++ -o max_subarray max_subarray.cpp
./max_subarray
```

## 🖥️ Sample Output

## 📌 Notes

- `INT_MIN` is used as the initial value of `maxSum` so the algorithm works correctly even for arrays containing only negative numbers.
- The Brute Force version additionally tracks and returns the **start and end indices** of the maximum subarray via reference parameters `i` and `j`.
- Kadane's Algorithm is the industry-standard optimal solution for this problem and is widely asked in coding interviews.

## 📄 License

This project is free to use for learning and educational purposes.
