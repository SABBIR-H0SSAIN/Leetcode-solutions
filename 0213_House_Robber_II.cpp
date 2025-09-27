// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return *max_element(nums.begin(),nums.end());
        return max(maxRob(nums,0,n-1),maxRob(nums,1,n));
    }

    int maxRob(vector<int>& nums,int l,int r) {
        int prev=nums[l];
        int curr=max(nums[l],nums[l+1]);

        for(int i=l+2;i<r;i++){
            int temp=curr;
            curr= max(curr,prev+nums[i]);
            prev=temp;
        }

        return curr;
    }
};
