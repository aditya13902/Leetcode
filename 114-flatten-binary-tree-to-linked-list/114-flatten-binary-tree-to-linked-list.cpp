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
    TreeNode* helper(TreeNode* root){
        if(!root){
            return root;
        }
        TreeNode* lft=helper(root->left);
        TreeNode* rgt=helper(root->right);
        root->left=NULL;
        if(lft==NULL){
            root->right=rgt;
            return root;
        }
        auto ptr=lft;
        while(ptr->right!=nullptr){
            ptr=ptr->right;
        }
        ptr->right=rgt;
        root->right=lft;
        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};