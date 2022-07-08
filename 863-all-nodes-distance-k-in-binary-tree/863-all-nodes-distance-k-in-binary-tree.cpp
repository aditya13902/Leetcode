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
    vector<int>ans;
    unordered_map<TreeNode*,int>vis;
    void traverse(TreeNode* node,int k){
        if(!node || vis[node]) return;
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        vis[node]=1;
        traverse(node->left,k-1);
        traverse(node->right,k-1);
        traverse(mp[node],k-1);
    }
    void parent(TreeNode* root,TreeNode* par){
        if(!root) return;
        mp[root]=par;
        parent(root->left,root);
        parent(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root,NULL);
        traverse(target,k);
        return ans;
    }
};