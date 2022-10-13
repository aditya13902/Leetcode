/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*prev=NULL;
        auto curr=node;
        auto nxt=node->next;
        while(nxt){
            curr->val=nxt->val;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        prev->next=NULL;
        
    }
};