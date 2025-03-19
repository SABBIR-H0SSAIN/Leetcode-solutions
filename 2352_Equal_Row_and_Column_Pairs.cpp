// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int count=0;
        
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }

        for(int i=0;i<grid.size();i++){
            vector<int>temp;
          
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            count+=mp[temp];
        }

        return count;
    }
};
