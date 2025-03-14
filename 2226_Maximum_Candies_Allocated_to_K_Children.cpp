// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
public:
    bool checkCandies(vector<int>& candies, long long k,int maxCandy){
        long long count=0;

        for(int i=0;i<candies.size();i++){
            count+=candies[i]/maxCandy;
        }

        return count >=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {

        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        int ans=0;

        while(l<=h){
            int mid=l+(h-l)/2;
            if(checkCandies(candies,k,mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};
