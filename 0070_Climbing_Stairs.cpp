// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/climbing-stairs/

//Recursive solution 
class Solution {
public:
    int calculateSteps(int n,vector<int>&memo){
        if(n<=2) return n;
        if(memo[n] != -1) return memo[n];
        return memo[n]=calculateSteps(n-1,memo)+calculateSteps(n-2,memo);
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return calculateSteps(n,memo);

    }
};


// DP Array Solution
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
