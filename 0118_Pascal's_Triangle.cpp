// Author: Sabbir Hossain 
// Problem Link: https://leetcode.com/problems/pascals-triangle/description/?envType=problem-list-v2&envId=maths-m3-combinatorics-permutations

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
        	vector<int>rows(i+1,1);
            for(int j=1;j<i;j++){
            	rows[j]=res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(rows);
        }
        return res;
    }
}; 
