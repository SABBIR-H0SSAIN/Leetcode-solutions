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

// More cleaner version
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mini=nums[0],maxi=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] < 0) swap(mini,maxi);

            maxi=max(maxi*nums[i],nums[i]);
            mini=min(mini*nums[i],nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};
