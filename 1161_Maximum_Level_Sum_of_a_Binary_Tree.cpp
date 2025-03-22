// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int maxsum=INT_MIN;
        int maxlevel=0,level=0;

        while(!q.empty()){
            level++;
            int levelsum=0;
            int k=q.size();

            while(k--){
                TreeNode *node=q.front();
                q.pop();

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
                levelsum+=node->val;
            }

            if(levelsum > maxsum){
                maxsum=levelsum;
                maxlevel=level;
            }
        }

        return maxlevel;
    }
};
