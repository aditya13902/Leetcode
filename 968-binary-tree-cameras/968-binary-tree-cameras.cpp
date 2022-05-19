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
    int needs=0;
    int has=1;
    int no=2;
    int cover=3;
    int cnt=0;
    int helper(TreeNode* root){
        if(!root){
            return no;
        }
        if(root->left==NULL && root->right==NULL){
            return needs;
        }
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==needs || r==needs){
            cnt++;
            return has;
        }
        if(l==has || r==has){
            return cover;
        }
        return needs;
    }
    int minCameraCover(TreeNode* root) {
        cnt=helper(root)==needs?cnt+1:cnt;
        return cnt;
    }
};