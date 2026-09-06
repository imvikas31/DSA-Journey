#include<bits/stdc++.h>
using namespace std;

// Insertion Sort:
// Pick an element from unsorted part and insert it
// at its correct position in the sorted part.

void insertionSort(vector<int>& nums){

    // Start from 2nd element because 1st element is already sorted.
    for(int i = 1; i < nums.size(); i++){

        // Current element to be placed at correct position.
        int curr = nums[i];

        // Element just before curr.
        int prev = i - 1;

        // Shift greater elements to the right
        // until we find the correct position for curr.
        while(prev >= 0 && curr < nums[prev]){
            nums[prev + 1] = nums[prev];
            prev--;
        }

        // Place curr at its correct position.
        nums[prev + 1] = curr;
    }
}

// Complexity Analysis:
// 1. Outer loop runs n times → O(n)
// 2. Inner while loop → O(n) in worst case
// 3. Worst Case TC → O(n²)
// 4. Best Case TC → O(n)
// 5. Space Complexity → O(1)

void print(vector<int>& nums){
    for(int el : nums){
        cout << el << " ";
    }
    cout << endl;
}

int main() {

    vector<int> nums = {5, 3, 4, 1, 2};

    cout << "Before Insertion Sort : ";
    print(nums);

    insertionSort(nums);

    cout << "After Insertion Sort : ";
    print(nums);

    return 0;
}