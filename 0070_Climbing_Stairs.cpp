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
