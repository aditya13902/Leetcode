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
    void flatten(TreeNode* root) {
        auto tmp=root;
        while(tmp){
            if(tmp->left){
                auto l=tmp->left;
                while(l->right){
                    l=l->right;
                }
                l->right=tmp->right;
                tmp->right=tmp->left;
                tmp->left=NULL;
            }
            tmp=tmp->right;
        }
    }
};