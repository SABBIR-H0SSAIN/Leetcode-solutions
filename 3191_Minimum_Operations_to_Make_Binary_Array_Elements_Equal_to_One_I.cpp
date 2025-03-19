// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=0;i+2<n;i++){
            if(nums[i]==0){
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                count++;

            }
        }

        return nums[n-1]+nums[n-2] < 2 ? -1 : count;
    }
};
