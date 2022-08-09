/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int cnt(ListNode* head){
        if(!head) return 0;
        return 1+cnt(head->next);
    }
    ListNode* head;
    TreeNode* helper(int n){
        if(n<=0 || head==NULL) return NULL;
        auto l=helper(n/2);
        TreeNode* root= new TreeNode(head->val);
        root->left=l;
        head=head->next;
        root->right=helper(n-n/2-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* node) {
        int n=cnt(node);
        head=node;
        return helper(n);
    }
};