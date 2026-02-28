// Author: Sabbir Hossain 
// Problem Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/description/?envType=problem-list-v2&envId=maths-m3-combinatorics-permutations

const int MOD = 1000000007 ;

class Solution {
public:
	int solve(int n,int k,vector<vector<int>>&dp){
    	if(n==k) return 1;
        
        if(n==0 || k==0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        
        return dp[n][k]=((solve(n-1,k-1,dp)%MOD)+((n-1)*1ll*solve(n-1,k,dp))%MOD)%MOD;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};
