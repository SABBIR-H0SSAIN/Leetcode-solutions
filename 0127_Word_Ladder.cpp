// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord == endWord) return 0;
        queue<pair<string,int>>q;
        unordered_set<string>st;
        q.push({beginWord,1});

        for(int i=0;i<wordList.size();i++){
            if(wordList[i]!=beginWord) st.insert(wordList[i]);
        }
     

        while(!q.empty()){

            string word=q.front().first;
            int count=q.front().second;
            if(word==endWord) return count;
            q.pop();

            for(int i=0;i<word.size();i++){
                for(char c='a';c<='z';c++){
                    string temp=word;
                    temp[i]=c;

                    if(st.count(temp)){
                        q.push({temp,count+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
