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
    unordered_map<int,int>mp;
    int height(TreeNode* root,int d){
        if(!root) return 0;
        mp[d]+=root->val;
        return 1+max(height(root->left,d+1),height(root->right,d+1));
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root,0);
        return mp[h-1];
    }
};