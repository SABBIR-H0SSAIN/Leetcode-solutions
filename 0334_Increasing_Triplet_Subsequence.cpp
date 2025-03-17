// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini=INT_MAX;
        int mid=INT_MAX;

        for(int i=0;i<nums.size();i++){
            
            if(nums[i]<=mini)mini=nums[i];
            else if(nums[i] <= mid) mid=nums[i];
            else return true;
        }
        return false;
    }
};
