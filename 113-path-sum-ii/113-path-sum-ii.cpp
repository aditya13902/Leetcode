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
    vector<vector<int>> ans;
    void helper(TreeNode* root,int target,int& sum,vector<int>& vec){
        if(!root){
            return;
        }
        sum+=root->val;
        vec.push_back(root->val);
        if(!root->left && !root->right && target==sum){
            ans.push_back(vec);
        }
        helper(root->left,target,sum,vec);
        helper(root->right,target,sum,vec);
        vec.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        int sum=0;
        vector<int>vec;
        helper(root,target,sum,vec);
        return ans;
    }
};