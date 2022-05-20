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
    int idx=0;
    TreeNode* helper(vector<int>& preorder,vector<int>&inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[idx++]);
        int i=s;
        while(inorder[i]!=root->val){
            i++;
        }
        root->left=helper(preorder,inorder,s,i-1);
        root->right=helper(preorder,inorder,i+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,inorder.size()-1);
    }
};