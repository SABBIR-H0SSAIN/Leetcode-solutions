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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        int left=maxDepth(root->left)+1;
        int right=maxDepth(root->right)+1;

        return max(left,right);
    }
};
