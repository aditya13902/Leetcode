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
    map<int,vector<pair<int,int>>>mp;
    void preorder(TreeNode* root,int d,int h){
        if(!root){
            return;
        }
        mp[d].push_back({h,root->val});
        preorder(root->left,d-1,h+1);
        preorder(root->right,d+1,h+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preorder(root,0,0);
        for(auto ele:mp){
            auto& vec=ele.second;
            sort(vec.begin(),vec.end());
        }
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            vector<int>tmp;
            sort(it.second.begin(),it.second.end());
            for(auto iit:it.second)
                tmp.push_back(iit.second);
            ans.push_back(tmp);
        }
        return ans;
    
    }
};
