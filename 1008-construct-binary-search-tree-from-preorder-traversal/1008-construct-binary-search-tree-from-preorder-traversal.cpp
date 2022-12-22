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
    TreeNode* helper(vector<int>& arr,int s,int e){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(arr[s]);
        int k=s+1;
        while(k<=e && arr[k]<arr[s]){
            k++;
        }
        // cout<<k<<endl;
        root->left=helper(arr,s+1,k-1);
        root->right=helper(arr,k,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        // idx=0;
        return helper(arr,0,arr.size()-1);
    }
};