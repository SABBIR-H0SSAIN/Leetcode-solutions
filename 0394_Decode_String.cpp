// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/decode-string

class Solution {
public:   
    bool isDigit(char c){
        return c>='0' && c<='9'; 
    }

    string decodeString(string s) {
        stack<char>st;

        for(char c: s){
            if(c!=']'){
                st.push(c);
              
            }else{
                string temp="";
              
                while(!st.empty() && st.top()!='['){
                    temp.push_back(st.top());
                    st.pop();
                }

                st.pop();
                string cnt="";

                while(!st.empty() && isDigit(st.top())){
                    cnt.push_back(st.top());
                    st.pop();
                }

                reverse(cnt.begin(),cnt.end());
                int count=stoi(cnt);

                while(count--){
                    for(int i=temp.size()-1;i>=0;i--){
                        st.push(temp[i]);
                    }
                }
            }
        }

        string ans(st.size(),'$');

        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
