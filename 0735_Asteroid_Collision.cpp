// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    bool canCollide(int a,int b){
        if((a<0 && b< 0) || (a>=0 && b>=0)) return false;
        return true;
    }

    int afterCollision(int a,int b){
        if(a+b==0) return 0;
        if(abs(a) > abs(b)) return a;
        return b;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int x : asteroids){
            if(x>=0){
                st.push(x);
            }else{
                while(!st.empty() && st.top() > 0  && canCollide(x,st.top())){
                    x=afterCollision(x,st.top());
                    st.pop();
                }
                if(x!=0)st.push(x);
            }
            
        }

        vector<int>ans(st.size());

        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
