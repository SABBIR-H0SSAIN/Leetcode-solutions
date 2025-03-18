// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int one=0,zero=0;
        int l=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            nums[i]==0 ? zero++ : one++;

            while(l<= i && zero > 1){
                nums[l++]==0 ? zero-- : one--;
            }
            ans=max(ans,one);
        }
        return ans == nums.size() ? ans-1 : ans;
    }
};
