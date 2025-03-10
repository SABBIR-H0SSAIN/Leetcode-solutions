// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

typedef long long ll;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        ll maxsum=0;
        ll csum=0;
        int l=0;
        unordered_map<int,int>feq;

        for(int i=0;i<nums.size();i++){
            feq[nums[i]]++;
            csum+=nums[i];

            while(i-l+1 >k || (l < i && feq[nums[i]]>1)){
                csum-=nums[l];
                feq[nums[l]]--;
                l++;
            }

            if(i-l+1 == k){
                maxsum=max(maxsum,csum);
            }
        }
        return maxsum;
    }   
};
