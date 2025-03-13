// Author : Sabbir Hossain
// Problem Link: https://leetcode.com/problems/zero-array-transformation-ii
// similar problem : 3355

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries,int k) {
        vector<int>diff(nums.size()+1,0);

        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];

            diff[l]+=val;
            diff[r+1]-=val;
        }

        for(int i=0;i<nums.size();i++){

            if(i>0) diff[i]+=diff[i-1];
            if(diff[i] < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int l=0;
        int h=queries.size();
        int mid,ans=-1;

        while(l<=h){
            mid=l+(h-l)/2;
          
            if(isZeroArray(nums,queries,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
      
        return ans;
    }
};
