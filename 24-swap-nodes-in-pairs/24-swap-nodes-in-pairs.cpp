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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* dummy=new ListNode(-1,head);
        ListNode* ptr=dummy;
        ListNode* first;
        ListNode* second;
        while(ptr->next && ptr->next->next){
            first=ptr->next;
            second=ptr->next->next;
            first->next=second->next;
            second->next=first;
            ptr->next=second;
            ptr=first;
        }
        return dummy->next;
        
    }
};