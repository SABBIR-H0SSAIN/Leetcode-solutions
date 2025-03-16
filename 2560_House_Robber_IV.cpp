// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/house-robber-iv/

class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int mincap){
        int count=0;
    
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= mincap){
                count++;
                i++;
            }
        }
        return count>=k;
    }

    int minCapability(vector<int>& nums, int k) {
        int l=nums[0],h=nums[0];

        for(int i=0;i<nums.size();i++){
            l=min(l,nums[i]);
            h=max(h,nums[i]);
        }

        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(nums,k,mid)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
