// Author: Sabbir Hossain 
// Problem Link: https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
	
	void solve(string &s,int i, vector<string>&ans){
    	if(i>= s.size()) {
        	ans.push_back(s);
            return;
        };
        char c=s[i];
        solve(s,i+1,ans);
        
        if(isalpha(s[i])){
        
        	s[i]^=32;
        	solve(s,i+1,ans);
            s[i]=c;
        }        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(s,0,ans);
        return ans;
    }
};