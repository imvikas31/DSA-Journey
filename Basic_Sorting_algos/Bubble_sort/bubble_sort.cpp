#include<bits/stdc++.h>
using namespace std;

// Bubble Sort Algo : 
// It a simplest sorting algorithms where 
// we compare the adjacent elements and if they are not in right sorted order then swap them.
// repeatedly perform this process for all the elements to sort the whole array.

// Brute Force Approach :
void bubbleSort(vector<int>&nums){
    for(int i = 0;i<nums.size();i++){
      
        for(vector<int>::iterator it = nums.begin()+1; it < nums.end()-i;it++){ // you can use simple loop instead of iterator as per you convenience.
            if(*it < *(it-1)){
                swap(*it, *(it-1));
            } 
        }
    }
}

// Brute Force Approach :
void bubbleSortOptimized(vector<int>&nums){
    for(int i = 0;i<nums.size();i++){
        bool flag = false;
        for(vector<int>::iterator it = nums.begin()+1; it < nums.end()-i;it++){ // you can use simple loop instead of iterator as per you convenience.
            if(*it < *(it-1)){
                swap(*it, *(it-1));
                flag = true;
            } else{
                if(flag){
                    break;
                }
            }
        }
    }
}



// Time Complexity = O(n²)

// The inner loop performs approximately n comparisons
// for each pass of the outer loop.

// The outer loop runs approximately n times.

// Therefore:
// n comparisons × n passes = n × n = O(n²)

// Space Complexity = O(1) No extra space is used.


// We can also find kth largest or kth smallest element using Bubble sort.
// Kth largest will be at the (n-k)th index where n is size of the array
// Kth smallest will be at the (k-1)th index
int secondLargest(vector<int>&nums){
    for(int i = 0;i<2;i++){
        for(vector<int>::iterator it = nums.begin()+1; it < nums.end()-i;it++){
        if(*it < *(it-1)){
            swap(*it, *(it-1));
        }
    }
    }
    int secondLargest = nums[nums.size()-2];
    return secondLargest;
}

void print(vector<int>&nums){
    for(int el : nums){
        cout<<el<<" ";
    }
    cout<<endl;
}

int main() {

    vector<int>nums = {501021,400,38,200,14};
    cout<<"Before Sorting : ";
    print(nums);

    bubbleSort(nums);

    cout<<"After Sorting : ";
    print(nums);

    bubbleSortOptimized(nums);
    cout<<"After Optimized Sorting : ";
    print(nums);

    int secondMax = secondLargest(nums);
    cout<<"Second largest element in nums is : "<<secondMax<<endl;
    
    return 0;
}