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

// Using bitwise to keep tract of used bits and xor to remove used bits
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,bits=0;
        int longest=0;

        for(int i=0;i<nums.size();i++){
            while((bits&nums[i]) !=0) bits^=nums[l++];

            bits|=nums[i];
            longest=max(longest,i-l+1);
        }
        return longest;
    }
};
