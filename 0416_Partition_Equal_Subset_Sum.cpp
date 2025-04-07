// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool rec(vector<int>&nums,int i,int target,int cur,vector<vector<int>>&dp){
        if(cur==target) return 1;
        if(cur > target) return 0;

        if(i>=nums.size()){
            return 0;
        }

        if(dp[cur][i] != -1) return dp[cur][i];

        int take=rec(nums,i+1,target,cur+nums[i],dp);
        int not_take=rec(nums,i+1,target,cur,dp);

        return dp[cur][i]=take|not_take;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;

        for(int i=0;i<nums.size();i++) sum+=nums[i];

        if(sum&1) return false;

        int target=sum/2;
        vector<vector<int>>dp(target+1,vector<int>(nums.size(),-1));
        return rec(nums,0,target,0,dp);
      
    }
};
