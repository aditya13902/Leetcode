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
    TreeNode* LCA(TreeNode* root,int a,int b){
        if(!root){
            return NULL;
        }
        if(root->val==a || root->val==b){
            return root;
        }
        auto l=LCA(root->left,a,b);
        auto r=LCA(root->right,a,b);
        if(l && r){
            return root;
        }
        if(l){
            return l;
        }
        if(r) return r;
        return NULL;
    }
    void helper(TreeNode* root,int a,string &s,string &ans){
        if(!root){
            return;
        }
        if(root->val==a){
            ans=s;
        }
        s+='L';
        helper(root->left,a,s,ans);
        s.pop_back();
        s+='R';
        helper(root->right,a,s,ans);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node=LCA(root,startValue,destValue);
        string s="";
        string d="";
        string str="";
        helper(node,startValue,str,s);
        helper(node,destValue,str,d);
        for(auto &ch:s){
            ch='U';
        }
        return s+d;
    }
};