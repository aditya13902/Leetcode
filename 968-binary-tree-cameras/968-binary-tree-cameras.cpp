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
    int no=0;
    int need=1;
    int has=2;
    int cover=3;
    int cnt=0;
    int helper(TreeNode* root) {
        if(!root){
            return no;
        }
        if(root->left==NULL && root->right==NULL){
            return need;
        }
        int lft=helper(root->left);
        int rgt=helper(root->right);
        if(lft==need || rgt==need){
            cnt++;
            return has;
        }
        if(lft==has || rgt==has){
            return cover;
        }
        return need; 
    }
    int minCameraCover(TreeNode* root) {
         return helper(root)==need?cnt+1:cnt;
    }
};