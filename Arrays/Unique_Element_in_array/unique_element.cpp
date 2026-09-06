#include<bits/stdc++.h>
using namespace std;



// Brute Force Approach--> TC = O(n^2) || SC = O(1)

int findUnique(vector<int>&nums){
    
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
   
    for(int i = 0;i<n;i++){
        int count = 1;
        for(int j = i+1;j<n;j++){
            if(nums[i] == nums[j] ){
                count++;
            }
        }
        if(count == 1){
            return nums[i];
        }
    }
    return -1;;
}
// Better Approach --> TC = O(n) || SC = O(n) [map used]

int findUniqueUsingMap(vector<int>&nums){
    
    int n = nums.size();
    unordered_map<int,int>map;
    if(n == 1){
        return nums[0];
    }
    
    for(int i = 0;i<n;i++){
        map[nums[i]]++;
    }

    for(auto &it : map){
        if(it.second == 1){
            return it.first;
        }
    }
        
    return -1;
}
// Optimal Approach --> TC = O(n) || SC = O(1)
int findUniqueUsingXOR(vector<int>&nums){
    
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans ^= nums[i];
    }
        
    return ans;
}



int main() {
    vector<int>nums = {2,3,5,4,2,3,4};

    int bruteForceAns = findUnique(nums);
    cout<<"Unique element that appears only once is : "<<bruteForceAns<<endl;

    int betterAns = findUniqueUsingMap(nums);
    cout<<"Unique element that appears only once is : "<<betterAns<<endl;

    int optimalAns = findUniqueUsingXOR(nums);
    cout<<"Unique element that appears only once is : "<<optimalAns<<endl;
    return 0;
}