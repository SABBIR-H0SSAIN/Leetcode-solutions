// Author: Sabbir Hossain;
// Problem Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    int maxVowels(string s, int k) {
        int l=0;
        int r=0;
        int v=0;
        int maxv=0;

        while(r < s.size()){
            if(isVowel(s[r])) v++;
            
            if(r-l+1 > k){
                if(isVowel(s[l++])) v--;
            };

            maxv=max(maxv,v);
            r++;
        }
        return maxv;
    }
};
