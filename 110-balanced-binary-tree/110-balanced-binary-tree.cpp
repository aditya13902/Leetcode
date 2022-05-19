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
        if(root==nullptr){
            return {0,1};
        }
        auto l=helper(root->left);
        auto r=helper(root->right);
        int lh=l.first;
        int rh=r.first;
        if(abs(lh-rh)<=1 && l.second && r.second){
            return {max(lh,rh)+1,1};
        }
        return {max(lh,rh)+1,0};
    }
    bool isBalanced(TreeNode* root) {
        auto p=helper(root);
        return p.second;
    }
};