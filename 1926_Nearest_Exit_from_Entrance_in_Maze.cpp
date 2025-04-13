// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
    int fx[4]={0,0,1,-1};
    int fy[4]={1,-1,0,0};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        int row=entrance[0],col=entrance[1];

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{row,col}});
        maze[row][col]='+';

        while(!q.empty()){
            int level=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            if((r==0 || r==m-1 || c==0 || c==n-1) && (r != row || c != col)){
                return level;
            }

            for(int k=0;k<4;k++){
                int nr=r+fx[k];
                int nc=c+fy[k];

                if(nr>=0 && nr<m && nc >=0 && nc<n){
                    if(maze[nr][nc]=='.'){
                        q.push({level+1,{nr,nc}});
                        maze[nr][nc]='+';
                    }
                }
            }
        }
        return -1;
    }
};
