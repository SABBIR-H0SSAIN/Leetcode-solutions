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

// Middle Index Approch O(n^2) solution
class Solution {
public:
    int oddPalindrome(string &s,int mid){
        int l=mid,r=mid,count=0;
        while(l>=0 && r<s.size() && s[l--]==s[r++]) count++;
        return count;
    }

    int evenPalindrome(string &s,int mid){
        int l=mid,r=mid+1,count=0;
        while(l>=0 && r<s.size() && s[l--]==s[r++]) count++;
        return count;
    }
   
    int countSubstrings(string s) {
        int count=0;
        
        for(int i=0;i<s.size();i++){
            count+=evenPalindrome(s,i);
            count+=oddPalindrome(s,i);
        }

        return count;
    }
};
