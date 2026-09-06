#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>&nums,int &i, int &j){

    int n = nums.size();
    int maxSum = INT_MIN;

    for(int start = 0;start<n;start++){
        
        for(int end = start; end<n;end++){
            int sum = 0;
            for(int k = start; k <=end;k++){
                
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

int main() {
    vector<int>nums = {5,4,-1,7,8};
    vector<int>el;

    int i,j;

    int ans = maxSubArraySum(nums,i,j);
    cout << "Maximum Subarray sum: " << ans << endl;

    cout << "Subarray with maximum sum start at index "<<i<<" and ends at index "<<j;

    return 0;
}