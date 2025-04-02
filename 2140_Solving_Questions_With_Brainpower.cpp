// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>points(questions.size()+1,0);
        int n=questions.size();
        
        for(int i=n-1;i>=0;i--){
            int point=questions[i][0];
            int bp=questions[i][1];

            long long skip=i+1 < n ? points[i+1] : 0;
            long long take=i+bp+1 < n ? point+points[i+bp+1] : point;
            
            points[i]=max(skip,take);
        }
        return points[0];
    }
};
