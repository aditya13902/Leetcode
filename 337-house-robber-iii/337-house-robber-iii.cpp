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
    map<pair<TreeNode*,int>,int>mp;
    int rob(TreeNode* root,int f=1) {
        if(!root){
            return 0;
        }
        if(mp.find({root,f})!=mp.end()){
            return mp[{root,f}];
        }
        if(f){
            int a=root->val+rob(root->left,0)+rob(root->right,0);
            int b=rob(root->left,1)+rob(root->right,1);
            return mp[{root,f}]=max(a,b);
        }
        else{
            return mp[{root,f}]=rob(root->left,1)+rob(root->right,1);
        }
        
    }
};