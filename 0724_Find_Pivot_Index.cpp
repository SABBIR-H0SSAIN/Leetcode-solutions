// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>pre(nums.size(),0);
        pre[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }

        for(int i=0;i<nums.size();i++){
            int left=0;
            int right=0;
            
            if(i > 0) left=pre[i-1];
            right=pre[nums.size()-1]-pre[i];

            if(left == right) return i;
        }
        return -1;
    }
};
