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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int f=1;
        
        while(q.size()){
            int l=q.size();
            vector<int>vec;
            while(l--){
                auto frnt=q.front();
                q.pop();
                if(frnt->left){
                    q.push(frnt->left);
                }
                if(frnt->right){
                    q.push(frnt->right);
                }
                vec.push_back(frnt->val);
            }
            if(f){
                ans.push_back(vec);
            }
            else{
                reverse(vec.begin(),vec.end());
                ans.push_back(vec);
            }
            f=!f;
            
        }
        return ans;
    }
};