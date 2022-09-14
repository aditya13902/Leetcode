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
    int ans=0;
    void helper(TreeNode* root,int bit){
        if(!root) return;
        bit^=(1<<root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(__builtin_popcount(bit)<=1) ans++;
        }
        helper(root->left,bit);
        helper(root->right,bit);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        helper(root,0);
        return ans;
    }
};