// Author : Sabbir Hossain
// Problem Link: https://leetcode.com/problems/zero-array-transformation-i/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff(nums.size()+1,0);

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];

            diff[l]++;
            diff[r+1]--;
        }

        for(int i=0;i<nums.size();i++){
            if(i>0) diff[i]+=diff[i-1];
            if(diff[i] < nums[i]) return false;
        }
      
        return true;
    }
};
