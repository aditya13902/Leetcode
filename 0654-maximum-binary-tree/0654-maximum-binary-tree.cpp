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
        int idx=s;
        for(int i=s;i<=e;i++){
            if(arr[idx]<arr[i]){
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(arr[idx]);
        root->left=helper(arr,s,idx-1);
        root->right=helper(arr,idx+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};