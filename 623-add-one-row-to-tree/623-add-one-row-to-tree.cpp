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
    TreeNode* helper(TreeNode* root,int val,int d,int curr){
        if(root==nullptr) return nullptr;
        if(curr==d-1){
            auto node1=new TreeNode(val);
            auto node2=new TreeNode(val);
            node1->left=root->left;
            node2->right=root->right;
            root->left=node1;
            root->right=node2;
            return root;
        }
        root->left=helper(root->left,val,d,curr+1);
        root->right=helper(root->right,val,d,curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            auto node=new TreeNode(val);
            node->left=root;
            return node;
        }
        return helper(root,val,depth,1);
    }
};