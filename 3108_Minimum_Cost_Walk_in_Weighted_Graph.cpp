// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
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

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int>ans;
        vector<int>cost(n+1,-1);

        for(int i=0;i<edges.size();i++){
            dsu.connect(edges[i][0],edges[i][1]);
        }

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int w=edges[i][2];
            int root= dsu.findParent(u);

            if(cost[root]==-1){
                cost[root]=w;
            }else{
                cost[root]&=w;
            }
        }

        for(int i=0;i<query.size();i++){
            int s=query[i][0];
            int t=query[i][1];

            if(!dsu.isConnected(s,t)){
                ans.push_back(-1);
            }else{
                ans.push_back(cost[dsu.findParent(s)]);
            }
        }

        return ans;
    }
};
