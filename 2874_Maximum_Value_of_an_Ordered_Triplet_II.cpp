// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxnum=0;
        int maxdiff=0;
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            ans=max(ans,nums[i]*1ll*maxdiff);
            maxnum=max(maxnum,nums[i]);
            maxdiff=max(maxdiff,maxnum-nums[i]);
        }
        
        return ans;
    }
};
