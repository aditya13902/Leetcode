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
    vector<TreeNode*>vec;
    void helper(TreeNode* root){
        if(!root){
            return;
        }
        helper(root->left);
        vec.push_back(root);
        helper(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        TreeNode* ptr=NULL;
        for(auto ele:vec){
            if(ptr){
                ptr->right=ele;
            }
            ele->left=NULL;
            ptr=ele;
        }
        return vec[0];
    }
};