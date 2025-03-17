// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/product-of-array-except-self

// @1st approch using (prefix and suffix Sum) O(n) time and O(n) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>presum(nums.size(),1);
        vector<int>postsum(nums.size(),1);

        for(int i=0;i<nums.size();i++){
            int j=nums.size()-i-1;
          
            presum[i]=nums[i]*(i>0 ? presum[i-1] : 1);
            postsum[j]=nums[j]*(j+1<nums.size() ? postsum[j+1] : 1);
        }

        for(int i=0;i<nums.size();i++){
            nums[i]=(i>0 ? presum[i-1] : 1)*(i+1 < nums.size() ? postsum[i+1] : 1);
        }
      
        return nums;
    }
};
