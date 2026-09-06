#include<bits/stdc++.h>
using namespace std;

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

int main() {
    vector<int>nums = {5,4,-1,7,8};
    int ans = maxSubArraySum(nums);
    cout<<"Maximum Subarray sum: "<<ans;

    
    
    return 0;
}