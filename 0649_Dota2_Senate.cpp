// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();

        queue<int>r;
        queue<int>d;
        
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }
        
        while(!r.empty() && !d.empty()){
            int ri=r.front();
            int di=d.front();

            if(ri<di){
                r.push(++n);
            }else{
                d.push(++n);
            }

            r.pop();
            d.pop();
        }

        if(d.empty()){
            return "Radiant";
        }else{
            return "Dire";
        }
    }
};
