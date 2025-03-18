// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/longest-nice-subarray

// @Bit manipulation technique (if xor==sum then xor & sum bitwise and must be zero)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sum=0,xsum=0;
        int l=0,longest=1;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            xsum^=nums[i];

            while(l<i && sum!=xsum){
                sum-=nums[l];
                xsum^=nums[l];
                l++;
            }
            longest=max(longest,i-l+1);
        }
        return longest;
    }
};
