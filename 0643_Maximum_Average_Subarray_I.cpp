// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double csum=0;
        double maxi= -1e4;
        int l=0;

        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(i-l+1 > k){
                csum-=nums[l++];
            }

            if(i-l+1==k) {
                maxi=max(maxi,csum/k);
            }
        }
        return maxi;
    }
};
