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
#define ull unsigned long long
class Solution {
public:
    map<ull,vector<ull>>mp;
    void helper(TreeNode* root,ull h,ull d){
        if(!root){
            return;
        }
        mp[h].push_back(d);
        helper(root->left,h+1,2*d+1);
        helper(root->right,h+1,2*d+2);
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        helper(root,0,0);
        ull ans=0;
        for(auto ele:mp){
            auto vec=ele.second;
            sort(vec.begin(),vec.end());
            ans=max(ans,vec[vec.size()-1]-vec[0]+1);
        }
        return ans;
    }
};