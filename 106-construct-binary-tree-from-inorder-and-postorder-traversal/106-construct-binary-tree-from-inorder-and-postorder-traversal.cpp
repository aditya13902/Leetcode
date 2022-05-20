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
    int idx;
    TreeNode* helper(vector<int>& postorder,vector<int>&inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[idx--]);
        int i=s;
        while(inorder[i]!=root->val){
            i++;
        }
        root->right=helper(postorder,inorder,i+1,e);
        root->left=helper(postorder,inorder,s,i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx=postorder.size()-1;
        return helper(postorder,inorder,0,inorder.size()-1);
    }
};