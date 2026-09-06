#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>&nums){

    int n = nums.size();
    int maxSum = INT_MIN;

    int currSum = 0;
    for(int el : nums){
       currSum += el;
       maxSum = max(currSum,maxSum);

       if(currSum < 0){
        currSum  = 0;
       }
        
    }
    return maxSum;

}

int main() {
    vector<int>nums = {5,4,-1,7,8};
    int ans = maxSubArraySum(nums);
    cout<<"Maximum Subarray sum: "<<ans;

    
    
    return 0;
}