// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool isBipertiteBFS(vector<vector<int>>&g,vector<int>&color,int source){
        color[source]=0;
        queue<int>q;
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int adj : g[node]){
                if(color[adj]==-1){
                    color[adj]=1-color[node];
                    q.push(adj);
                }else if(color[adj] == color[node]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>g(n+1);
        vector<int>color(n+1,-1);

        for(int i=0;i<dislikes.size();i++){
            int u= dislikes[i][0];
            int v= dislikes[i][1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!isBipertiteBFS(g,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
};
