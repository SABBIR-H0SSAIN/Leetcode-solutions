// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/flood-fill/

class Solution {
public:
void dfs(vector<vector<int>>&img,int r,int c,int init_color,int color){

    if(r<0 || r>=img.size() || c<0 || c>= img[0].size() || img[r][c]!=init_color) return;

    img[r][c]=color;

    dfs(img,r+1,c,init_color,color);
    dfs(img,r-1,c,init_color,color);
    dfs(img,r,c+1,init_color,color);
    dfs(img,r,c-1,init_color,color);
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int init_color = image[sr][sc];
        if(init_color==color) return image;

        dfs(image,sr,sc,init_color,color);
        return image;
    }
};
