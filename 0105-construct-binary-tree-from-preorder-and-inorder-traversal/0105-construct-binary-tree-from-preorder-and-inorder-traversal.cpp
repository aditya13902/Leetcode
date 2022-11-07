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
    TreeNode* build(vector<int>&preorder,vector<int>& inorder,int s,int e){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(preorder[idx++]);
        int i=s;
        for(;i<=e;i++){
            if(inorder[i]==root->val){
                break;
            }
        }
        root->left=build(preorder,inorder,s,i-1);
        root->right=build(preorder,inorder,i+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx=0;
        return build(preorder,inorder,0,inorder.size()-1);
    }
};