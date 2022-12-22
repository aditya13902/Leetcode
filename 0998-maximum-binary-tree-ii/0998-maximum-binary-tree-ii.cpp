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
    TreeNode* helper(TreeNode* root,TreeNode* node){
        if(!root) return node;
        if(root->val<node->val){
            node->left=root;
            return node;
        }
        else{
            if(root->right){
                root->right=helper(root->right,node);
            }
            else{
                root->right=node;
            }
            return root;
        }
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        return helper(root,node);
    }
};