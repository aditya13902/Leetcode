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
    int ans;
    int helper(TreeNode* root){
        if(!root) return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        ans=max(ans,root->val+max(0,l)+max(0,r));
        return max(0,root->val+max(0,max(l,r)));
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        helper(root);
        return ans;
    }
};