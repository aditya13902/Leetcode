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
    int need=1;
    int has=2;
    int cover=3;
    int ans=0;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return need;
        }
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==need || r==need){
            ans++;
            return has;
        }
        if(l==has || r==has){
            return cover;
        }
        return need;
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==need){
            ans++;
        }
        return ans;
    }
};