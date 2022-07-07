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
    vector<int>store;
    unordered_map<int,TreeNode*>mp;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        store.push_back(root->val);
        mp[root->val]=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        TreeNode* first=NULL;
        TreeNode* middle=NULL;
        TreeNode* second=NULL;
        for(int i=0;i<store.size()-1;i++){
            if(store[i]>store[i+1]){
                if(first==nullptr){
                    first=mp[store[i]];
                    middle=mp[store[i+1]];
                }
                else{
                    second=mp[store[i+1]];
                }
            }
        }
        if(second){
            swap(first->val,second->val);
        }
        else{
            swap(first->val,middle->val);
        }
    }
};