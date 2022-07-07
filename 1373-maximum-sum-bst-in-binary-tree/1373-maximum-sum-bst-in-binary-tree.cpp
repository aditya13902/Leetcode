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
    int mx;
    int mn;
    bst(int sum,int mx,int mn){
        this->sum=sum;
        this->mx=mx;
        this->mn=mn;
    }
};

class Solution {
public:
    int ans=0;
    bst* helper(TreeNode* root){
        if(!root){
            bst* bstnode=new bst(0,INT_MIN,INT_MAX);
            return bstnode;
        }
        bst* l= helper(root->left);
        bst* r= helper(root->right);
        if(root->val>l->mx && root->val<r->mn){
            int suml=l->sum;
            int sumr=r->sum;
            ans=max(suml+sumr+root->val,ans);
            return new bst(suml+sumr+root->val,max(root->val,r->mx),min(root->val,l->mn));
        }
        return new bst(max(l->sum,r->sum),INT_MAX,INT_MIN);
    }
    int maxSumBST(TreeNode* root) {
        auto bstnode=helper(root);
        return ans;
    }
};