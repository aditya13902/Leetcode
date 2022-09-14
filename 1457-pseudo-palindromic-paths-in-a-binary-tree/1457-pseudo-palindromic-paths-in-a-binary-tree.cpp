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
    bool check(unordered_map<int,int>&mp){
        int siz=mp.size();
        int cnt=0;
        for(auto it:mp){
            if(it.second&1){
                cnt++;
            }
        }
        return cnt<=1;
    }
    void helper(TreeNode* root,unordered_map<int,int>&mp){
        if(!root) return;
        mp[root->val]++;
        if(!root->left && !root->right){
            if(check(mp)) ans++;
        }
        helper(root->left,mp);
        helper(root->right,mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        helper(root,mp);
        return ans;
    }
};