// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int mini=1,maxi=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                mini=maxi=1;
                continue;
            }
            
            int tmp=nums[i]*maxi;
            maxi=max(nums[i],max(nums[i]*mini,nums[i]*maxi));
            mini=min(nums[i],min(nums[i]*mini,tmp));
            ans=max(ans,maxi);
        }
        return ans;
    }
};
