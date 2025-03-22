// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/count-the-number-of-complete-components

// @BFS approch solution
class Solution {
public:
    pair<int,int> bfs(int n,vector<vector<int>>&g,vector<bool>&visited,int source){
        queue<int>q;
        q.push(source);
        visited[source]=true;
      
        int nodes=1;
        int edges=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto adj: g[node]){
                edges++;
              
                 if(!visited[adj]){
                    nodes++;
                    q.push(adj);
                    visited[adj]=true;
                }
            }

        }
        return {nodes,edges};

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        vector<bool>visited(n,false);
        int count=0;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            auto [v,e]=bfs(n,g,visited,i);
            count += (e==v*(v-1));
        }
        return count;
    }
};
