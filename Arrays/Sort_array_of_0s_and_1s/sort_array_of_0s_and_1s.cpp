#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach  - Tc = O(nlogn) and SC = O(log n)
// sort the array that takes O(nlogn)  time complexity.
// modifies the array in place, but it is not allowed because the problem expects us to implement the sorting logic ourselves.

void sortUsingSortFun(vector<int>&nums){
    sort(nums.begin(), nums.end());
}

// Approach 2 : counting method -> count zeros and ones and then fill in the array as per their counts.
// But here we are overwriting the the array elements, we have to do inplace, without modifying hte original array.
// TC = O(n) and SC = O(1)

void sortUsingCounting(vector<int>&nums){
    int zeros = 0;
    int ones = 0;

    int i = 0;
    while(i < nums.size()){
        if(nums[i] == 0){
            zeros++;
        }else{
            ones++;
        }
        i++;
    }

    int index = 0;
    while(zeros != 0){
        nums[index] = 0;
        zeros--;
        index++;
    }
    while(ones != 0){
        nums[index] = 1;
        ones--;
        index++;
    }
}


// Optimal approach : TC = o(n) and SC = O(1) and inplace sorting without modifying the original array.
void sortZerosAndOnes(vector<int>&nums){
    int i = 0;
    int j = 0;

    while(j < nums.size()){
        if(nums[j] == 0){
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}

int main() {
    vector<int>nums = {0,1,0,1,0,1};

    // sortUsingSortFun(nums);
    // sortZerosAndOnes(nums);
    sortUsingCounting(nums);

    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}