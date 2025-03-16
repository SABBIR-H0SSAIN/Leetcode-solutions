// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int max_rob(vector<int>&nums,int l,int r){

        int prev=nums[l];
        int cur=max(nums[l],nums[l+1]);

        for(int i=l+2;i<r;i++){
            int temp=max(cur,prev+nums[i]);
            prev=cur;
            cur=temp;
        }
        return cur;
    }

    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        return max(max_rob(nums,0,n-1),max_rob(nums,1,n));
    }
};
