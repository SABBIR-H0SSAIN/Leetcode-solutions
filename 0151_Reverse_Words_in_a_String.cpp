// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(),s.end());
        int i=0,l=0,r=0;

        while(i<s.size()){
            while(i<s.size() && s[i] == ' ')i++;

            if(i<s.size()){
                while(i<s.size() && s[i] !=' '){
                    s[r++]=s[i++];
                }
                reverse(s.begin()+l,s.begin()+r);
                s[r++]=' ';
                i++;
                l=r;
            }
        }
        s.resize(--r);
        return s;

    }
};
