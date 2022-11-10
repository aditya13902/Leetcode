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
    int sumOfLeftLeaves(TreeNode* root,int f=0) {
        if(!root) return 0;
        if(!root->left && !root->right){
            if(f){
                return root->val;
            }
            return 0;
        }
        int ans=0;
        ans+=sumOfLeftLeaves(root->left,1);
        ans+=sumOfLeftLeaves(root->right,0);
        return ans;
    }
};