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
class BSTIterator {
private:
    stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
       pushall(root);
    }
    void pushall(TreeNode* root){
        while(root){
           st.push(root);
           root=root->left;
       } 
    }
    int next() {
        auto curr=st.top();
        st.pop();
        if(curr->right){
            pushall(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return st.size()!=0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */