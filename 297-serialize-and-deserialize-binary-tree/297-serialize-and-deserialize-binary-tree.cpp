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
    void buildstr(TreeNode* root,string &res){
        if(!root){
            res+="null,";
            return;
        }
        res+=to_string(root->val)+",";
        buildstr(root->left,res);
        buildstr(root->right,res);
    }
    string serialize(TreeNode* root) {
        string res="";
        buildstr(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* buildtree(queue<string>&q){
        auto top=q.front();
        q.pop();
        if(top=="null"){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(top));
        root->left=buildtree(q);
        root->right=buildtree(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue<string>q;
        string s="";
        for(auto ch:data){
            if(ch==','){
                q.push(s);
                s="";
            }
            else{
                s+=ch;
            }
        }
        return buildtree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));