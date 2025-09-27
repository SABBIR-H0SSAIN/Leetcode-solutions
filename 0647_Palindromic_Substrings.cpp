// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/palindromic-substrings

// Brute force approch O(n^3) time
class Solution {
public:
    bool isPalindrome(string &s ,int l,int r){
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(isPalindrome(s,j,i)) count++;
            }
        }

        return count; 
    }
};
