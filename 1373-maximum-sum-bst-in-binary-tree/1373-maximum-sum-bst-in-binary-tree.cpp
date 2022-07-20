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
class bst{
public:
    int sum;
    int mn;
    int mx;
    bst(int sum,int mn,int mx){
        this->sum=sum;
        this->mn=mn;
        this->mx=mx;
    }
    
};
class Solution {
private:
    int ans=0;
    bst* helper(TreeNode* root){
        if(!root){
            return new bst(0,INT_MAX,INT_MIN);
        }
        bst* l=helper(root->left);
        bst* r=helper(root->right);
        if(root->val>l->mx && root->val<r->mn){
            ans=max(ans,root->val+l->sum+r->sum);
            return new bst(root->val+l->sum+r->sum,min(root->val,l->mn),max(root->val,r->mx));
        }
        return new bst(max(l->sum,r->sum),INT_MIN,INT_MAX);
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};