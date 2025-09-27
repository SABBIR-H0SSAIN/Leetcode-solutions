// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs

//O(n) space solution using dp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<=2) return *min_element(cost.begin(),cost.end());

        vector<int>dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-2]+cost[i],dp[i-1]+cost[i]);
        }

        return min(dp[n-1],dp[n-2]);
    }
};
