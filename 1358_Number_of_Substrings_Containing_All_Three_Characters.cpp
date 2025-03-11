// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    bool valid(auto &mp){
        return (mp['a'] && mp['b'] && mp['c']);
    }

    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int l=0,ans=0;
      
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;

            while(valid(mp) && l<=i){
                ans+=s.size()-i;
                mp[s[l++]]--;
            }
        }
        return ans;
    }
};
