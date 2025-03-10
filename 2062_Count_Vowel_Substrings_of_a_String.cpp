// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/count-vowel-substrings-of-a-string/

class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    int countVowelSubstrings(string word) {
        int ans=0;
       
        for(int i=0;i<word.size();i++){
          
            if(isVowel(word[i])){
                set<char>st;
                int j=i;
              
                while(j<word.size() && isVowel(word[j])){
                    st.insert(word[j]);
                    if(st.size()>=5) ans++;
                    j++;
                }
            }
        }
        return ans;
    }
};
