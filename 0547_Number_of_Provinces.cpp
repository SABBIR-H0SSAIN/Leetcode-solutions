// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void convert_adj_list(vector<vector<int>>& mat,vector<vector<int>>&adj_list){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j]==1){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
    }

    void dfs(vector<vector<int>>&g,vector<bool>&vis,int source){
        if(vis[source]) return;
        vis[source]=true;
      
        for(int child : g[source]){
            if(vis[child]) continue;
            dfs(g,vis,child);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
      
        vector<vector<int>>adj_list(n+1);
        vector<bool>vis(n+1,false);
        convert_adj_list(isConnected,adj_list);
      
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(adj_list,vis,i);
                count++;
            }

        }
        return count;
    }
};
