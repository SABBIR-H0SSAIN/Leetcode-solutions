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


// @DFS approch solution
class Solution {
public:
    void dfs(int n,vector<vector<int>>&g,vector<bool>&visited,int &v,int &e,int source){
        visited[source]=true;
        v++;
        e+=g[source].size();

        for(auto adj : g[source]){
            if(!visited[adj]){
                dfs(n,g,visited,v,e,adj);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        vector<bool>visited(n,false);
        int count=0,v,e;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            v=e=0;
            
            dfs(n,g,visited,v,e,i);
            count += (e==v*(v-1));
        }
        return count;
    }
};


// @DSU approch solution
class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int child) {
        if (parent[child] == child) return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void connect(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            if (size[u] > size[v]) {
                parent[v] = u;
                size[u] += size[v];
            } else {
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }

    int getSize(int node) {
        return size[findParent(node)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int count=0;
        unordered_map<int,int>edgeCount;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            dsu.connect(u,v);
        }
        
        for(int i=0;i<edges.size();i++){
            edgeCount[dsu.findParent(edges[i][0])]++;
        }
 
        for(int i=0;i<n;i++){
            if(dsu.findParent(i)==i){
                int v=dsu.getSize(i);
                int e=edgeCount[i];
                count+=(e==v*(v-1)/2);
            }
        }
        return count;
    }
};
