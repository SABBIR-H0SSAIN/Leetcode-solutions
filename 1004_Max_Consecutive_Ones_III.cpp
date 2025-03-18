// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,one=0,zero=0;
        int ans=INT_MIN;

        for(int i=0;i<nums.size();i++){
            nums[i]==1 ? one++ : zero++;

            while(l < i && zero > k){
                nums[l++]==1 ? one-- : zero--;
            }
            ans=max(ans,one+min(k,zero));
        }

        return ans;
    }
    
};
