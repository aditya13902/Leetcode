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
    unordered_map<string,TreeNode*>mp;
    set<TreeNode*>ans;
    string helper(TreeNode* root){
        if(!root){
            return "null";
        }
        auto l=helper(root->left);
        auto r=helper(root->right);
        string str=to_string(root->val)+"L,"+l+"R,"+r;
        if(mp.find(str)!=mp.end()){
            ans.insert(mp[str]);
        }
        else{
            mp[str]=root;
        }
        
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        helper(root);
        vector<TreeNode*>vec;
        for(auto ele:ans){
            vec.push_back(ele);
        }
        return vec;
    }
};