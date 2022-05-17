/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void traverse(TreeNode* original, TreeNode* cloned){
        if(original==NULL){
            return;
        }
        mp[original]=cloned;
        traverse(original->left,cloned->left);
        traverse(original->right,cloned->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original,cloned);
        return mp[target];
    }
};