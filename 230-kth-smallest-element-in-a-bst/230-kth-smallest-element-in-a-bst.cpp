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
    int cnt;
    int ans;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        cnt--;
        if(cnt==0){
            ans=root->val;
            return;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt=k;
        ans=-1;
        inorder(root);
        return ans;
    }
};