// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void helper(TreeNode* root,vector<vector<int>> &out,map<int,vector<int>>&mymap,int dist){
//         if(root==NULL){
//             return;
//         }
//         mymap[dist].push_back(root->val);
//         helper(root->left,out,mymap,dist-1);
//         helper(root->right,out,mymap,dist+1);
        
//     }
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> out;
//         map<int,vector<int>> mymap;
//         helper(root,out,mymap,0);
//         for(auto it:mymap){
//             vector<int>&vec=it.second;
//             sort(vec.begin(),vec.end());
//             out.push_back(vec);
//         }
//         return out;
        
        
        
//     }
// };
class Solution {
public:
    void fun(TreeNode*root,map<int,vector<pair<int,int>>>&m,int w,int h)
    {
        if(root==NULL)
            return;
        m[w-1].push_back({h+1,root->val});
        fun(root->left,m,w-1,h+1);
        fun(root->right,m,w+1,h+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        map<int,vector<pair<int,int>>>m;
        fun(root,m,0,0);
        for(auto it:m)
        {
            vector<int>tmp;
            sort(it.second.begin(),it.second.end());
            for(auto iit:it.second)
                tmp.push_back(iit.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};