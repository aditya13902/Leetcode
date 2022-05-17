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
    int sum(TreeNode* root){
        if(!root){
            return 0;
        }
        int l_sum=sum(root->left);
        int r_sum=sum(root->right);
        l_sum=max(l_sum,0);
        r_sum=max(r_sum,0);
        ans=max(ans,l_sum+r_sum+root->val);
        return max(l_sum,r_sum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return ans;
    }
};