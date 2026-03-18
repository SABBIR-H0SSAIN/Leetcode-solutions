// Author: Sabbir Hossain 
// Problem Link: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void solve(string &s, int open,int close, vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        if(open>0){
            s.push_back('(');
            solve(s,open-1,close,ans);
            s.pop_back();
        }
        
        if(close>0 && open!=close){
            s.push_back(')');
            solve(s,open,close-1,ans);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        solve(s,n,n,ans);
        return ans;
    }
};