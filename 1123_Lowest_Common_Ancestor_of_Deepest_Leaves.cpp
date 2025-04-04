// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

class Solution {
public:
    pair<TreeNode*,int>rec(TreeNode *root){
        if(root==nullptr) return {nullptr,0};

        auto left=rec(root->left);
        auto right=rec(root->right);

        if(left.second == right.second){
            return {root,left.second+1};
        }

        if(left.second > right.second){
            return {left.first,left.second+1};
        }
       
        return {right.first,right.second+1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return rec(root).first;
    }
};
