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
    vector<int> helper(TreeNode* root){ // {max,min,sum}
        if(!root) return {INT_MIN,INT_MAX,0};
        auto l=helper(root->left);
        auto r=helper(root->right);
        if(root->val>l[0] && root->val<r[1]){
            ans=max(ans,root->val+r[2]+l[2]);
            return {max(r[0],root->val),min(root->val,l[1]),root->val+r[2]+l[2]};
        }
        return {INT_MAX,INT_MIN,0};
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};