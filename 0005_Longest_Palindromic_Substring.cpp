Author: sabbir Hossain
Problem Link: https://leetcode.com/problems/longest-palindromic-substring

// Brute force approch
class Solution {
public:
    bool isPalindrome(string &s ,int l,int r){
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int max_len=1;
        int startIdx=0;
        for(int i=1;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(isPalindrome(s,j,i)){
                    int size=i-j+1;
                    if(size > max_len){
                        max_len=size;
                        startIdx=j;
                    }
                }
            }
        }

        return s.substr(startIdx,max_len);
        
    }
};
