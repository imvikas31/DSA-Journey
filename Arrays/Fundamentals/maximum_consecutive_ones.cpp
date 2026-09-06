#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    int count;
    vector<int>nums;

    Solution(int ans, int count, int n){
        this->ans = ans;
        this->count = count;
        nums.resize(n);

        cout<<"Enter Element : ";
        for(int i = 0;i<n;i++){
            int el;
            cin>>nums[i];
        }

    }
    
    int findMaxConsecutiveOnes(int index) {
        // int count = 0;
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     if(nums[i] != 1){
        //         count = 0;
        //     }else{
        //         count++;
        //         ans = max(count, ans);
        //     }
        // }

        if(index >= nums.size() || nums.size() <= 0){
            return 0;
        }

        
        if(nums[index] != 1){
            count = 0;
        }else{
            count++;
            ans = max(ans,count);
        }

        findMaxConsecutiveOnes(index+1);
        return ans;
    }
};

int main() {

    Solution s1(0,0,5);
    
    int ans = s1.findMaxConsecutiveOnes(0);
    cout<<"Maximum consecutvive ones are : "<<ans<<endl;

    return 0;
}