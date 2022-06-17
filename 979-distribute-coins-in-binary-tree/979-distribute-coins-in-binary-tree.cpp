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
    int moves=0;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int lft=dfs(root->left);
        int rgt=dfs(root->right);
        moves+=abs(lft)+abs(rgt);
        return root->val+lft+rgt-1;
        
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};