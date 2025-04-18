// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/count-and-say

class Solution {
public:
    string RLE(string s){
        if(s=="1") return "11";

        string ans="";
        int i=0;

        while(i<s.size()){
            int count=0;
            char c=s[i];
            int start=i;

            while(i<s.size() && s[i] == c) i++;
            ans+=to_string(i-start);
            ans.push_back(c);  
        }
        
        return ans;
    }

    string countAndSay(int n) {
        string ans="1";

        for(int i=2;i<=n;i++){
            ans=RLE(ans);
        }

        return ans;
    }
};
