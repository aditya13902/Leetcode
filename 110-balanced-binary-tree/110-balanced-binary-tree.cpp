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
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,1};
        auto l=helper(root->left);
        auto r=helper(root->right);
        // {h,flag}
        if(abs(l.first-r.first)<=1 && l.second && r.second) return {1+max(l.first,r.first),1};
        return {1+max(l.first,r.first),0};
    }
    bool isBalanced(TreeNode* root) {
        auto ans=helper(root);
        return ans.second;
    }
};