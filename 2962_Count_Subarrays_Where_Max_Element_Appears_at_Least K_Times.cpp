// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int count=0;
        int max_num = *max_element(nums.begin(),nums.end());
        int l=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == max_num) count++;
            
            while(l<=i && count == k) count-=nums[l++]==max_num;
            ans+=l;
        }
        return ans;
    }
};
