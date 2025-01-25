// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/01-matrix/

class Solution {
public:
    int fx[4]={-1,1,0,0};
    int fy[4]={0,0,-1,1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,1e8));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int r=i+fx[k];
                int c=j+fy[k];

                if(r>=0 && c>=0 && r<m && c<n){
                    if(dist[r][c]>dist[i][j]+1){
                        dist[r][c]=dist[i][j]+1;
                        q.push({r,c});
                    }
                }
            }
        }
        return dist;
    }
};
