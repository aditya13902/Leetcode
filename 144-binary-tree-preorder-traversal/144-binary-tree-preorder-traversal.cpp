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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        stack<TreeNode*>st;
        vector<int>ans;
        while(q.size()){
            auto curr=q.front();
            q.pop();
            ans.push_back(curr->val);
            st.push(curr);
            if(curr->left){
                q.push(curr->left);
            }
            else{
                while(st.size() && !(st.top()->right)){
                    st.pop();
                }
                if(st.size()){
                    auto node=st.top();
                    st.pop();
                    
                    q.push(node->right);   
                }
                
            }
        }
        return ans;
    }
};