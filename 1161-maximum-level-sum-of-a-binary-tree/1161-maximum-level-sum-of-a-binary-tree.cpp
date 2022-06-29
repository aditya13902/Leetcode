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
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=-1e9;
        queue<TreeNode*>q;
        q.push(root);
        int d=1;
        int lvl=0;
        while(q.size()){
            int l=q.size();
            int curr=0;
            while(l--){
                auto top=q.front();
                q.pop();
                curr+=top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            if(curr>ans){
                ans=curr;
                lvl=d;
            }
            d++;
        }
        return lvl;
    }
};