Author: sabbir Hossain
Problem Link: https://leetcode.com/problems/longest-palindromic-substring

// Brute force approch O(n^3) time
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

// Middle index method O(n^2) method
class Solution {
public:
    void oddPalindrome(string &s,int mid,int &startIdx, int &maxLen){
        int l=mid,r=mid;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                startIdx=l;
                maxLen=r-l+1;
            }
            l--,r++;
        }
    }

    void evenPalindrome(string &s,int mid,int &startIdx, int &maxLen){
        int l=mid,r=mid+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                startIdx=l;
                maxLen=r-l+1;
            }
            l--,r++;
        }
    }
    string longestPalindrome(string s) {
        int startIdx=0;
        int maxLen=1;

        for(int i=0;i<s.size();i++){
            evenPalindrome(s,i,startIdx,maxLen);
            oddPalindrome(s,i,startIdx,maxLen);
        }

        return s.substr(startIdx,maxLen);
    }
};
        
    }
};
