// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/binary-tree-right-side-view

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int>ans;
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});

        while(!q.empty()){
            TreeNode *node=q.front().first;
            int level=q.front().second;
            q.pop();

            if(level == ans.size()){
                ans.push_back(node->val);
            }else{
                ans[level]=node->val;
            }

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        return ans;
    }
};
