/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root,string &res){
        if(!root) {
            res+='N';
            res+=',';
            return;
        }
        res+=(to_string(root->val));
        res+=',';
        dfs(root->left,res);
        dfs(root->right,res);
    }
    string serialize(TreeNode* root) {
        string res="";
        dfs(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(string data,int& idx){
        string s="";
        for(;data[idx]!=',';idx++){
            s+=data[idx];
        }
        idx++;
        if(s=="N"){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(s));
        root->left=helper(data,idx);
        root->right=helper(data,idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i=0;
        return helper(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));