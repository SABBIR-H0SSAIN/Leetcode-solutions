// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// @Recursive Solution
class Solution {
public:
    int depth(TreeNode *root,int dep){
        if(root == nullptr) return dep;

        int left=depth(root->left,dep+1);
        int right=depth(root->right,dep+1);
        
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return depth(root,0);
    }
};
