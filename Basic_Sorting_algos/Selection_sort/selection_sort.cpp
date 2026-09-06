#include<bits/stdc++.h>
using namespace std;

// Selection Sort:
// Pick the smallest element from the unsorted part
// and place it at the beginning of the unsorted part.

void selectionSort(vector<int>& nums){

    // Move through each position of the array.
    for(int i = 0; i < nums.size(); i++){

        // Assume current element is the smallest.
        int miniIndex = i;

        // Find the smallest element in the unsorted part.
        for(int j = i + 1; j < nums.size(); j++){

            if(nums[j] < nums[miniIndex]){
                miniIndex = j;
            }
        }

        // Place the smallest element at its correct position.
        if(miniIndex != i){
            swap(nums[i], nums[miniIndex]);
        }
    }
}

// Complexity Analysis:
// 1. Outer loop runs n times → O(n)
// 2. Inner loop runs up to n times → O(n)
// 3. Overall Time Complexity → O(n²)
// 4. Best, Average, Worst Case → O(n²)
// 5. Space Complexity → O(1)

void print(vector<int>& nums){
    for(int el : nums){
        cout << el << " ";
    }
    cout << endl;
}

int main() {

    vector<int> nums = {5, 3, 4, 1, 2};

    cout << "Before Selection Sort : ";
    print(nums);

    selectionSort(nums);

    cout << "After Selection Sort : ";
    print(nums);

    return 0;
}