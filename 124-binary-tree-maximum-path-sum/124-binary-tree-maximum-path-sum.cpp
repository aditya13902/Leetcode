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
    int ans=INT_MIN;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int lft=helper(root->left);
        int rgt=helper(root->right);
        ans=max(ans,max(0,lft)+max(0,rgt)+root->val);
        return root->val+max(0,max(lft,rgt));
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};