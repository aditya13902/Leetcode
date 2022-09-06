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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(q.size()){
            int mn=INT_MAX;
            int mx=INT_MIN;
            int l=q.size();
            while(l--){
                auto [curr,v]=q.front();
                q.pop();
                mn=min(mn,v);
                mx=max(mx,v);
                if(curr->left){
                    q.push({curr->left,(long long)2*v+1});
                }
                if(curr->right){
                    q.push({curr->right,(long long)2*v+2});
                }
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};