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
class BstIterator{
private:
    stack<TreeNode*>st;
    bool f;
public:
    BstIterator(TreeNode* root,int f){
        this->f=f;
        pushall(root);
    }
    void pushall(TreeNode*root){
        if(f){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
        else{
            while(root){
                st.push(root);
                root=root->right;
            }
        }
    }
    int get(){
        auto node=st.top();
        st.pop();
        if(f){
            if(node->right){
                pushall(node->right);
            }
        }
        else{
            if(node->left){
                pushall(node->left);
            }
        }
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BstIterator* l=new BstIterator(root,1);
        BstIterator* r=new BstIterator(root,0);
        int i=l->get();
        int j=r->get();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i=l->get();
            }
            else{
                j=r->get();
            }
        }
        return false;
        
    }
};