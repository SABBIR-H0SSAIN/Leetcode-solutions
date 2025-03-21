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

// Iterative solution using bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=0;

        while(!q.empty()){
            TreeNode *node=q.front().first;
            int depth=q.front().second;
            ans=max(ans,depth);
            q.pop();

            if(node->left) q.push({node->left,depth+1});
            if(node->right) q.push({node->right,depth+1});
        }

        return ans;
    }
};
