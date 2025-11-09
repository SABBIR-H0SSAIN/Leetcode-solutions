// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/n-queens

class Solution {
public:
    bool safe(vector<vector<char>>&board,int row,int col){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q' || board[i][col]=='Q') return false;
        }

        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(board[i--][j--]=='Q') return false;
        }

        i=row-1,j=col+1;
        while(i>=0 && j <n){
            if(board[i--][j++]=='Q') return false;
        }
        return true;
    }

    void solve(vector<vector<char>>&board,int row,int col,vector<vector<string>>&result){
        int n=board.size();

        if(n==row){
            vector<string>tmp(n,"");

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    tmp[i].push_back(board[i][j]);
                }
            }
            return result.push_back(tmp);
        }

        for(int i=0;i<n;i++){
            if(safe(board,row,i)){
                board[row][i]='Q';
                solve(board,row+1,i,result);
                board[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>result;
        solve(board,0,0,result);
        return result;
    }
};
