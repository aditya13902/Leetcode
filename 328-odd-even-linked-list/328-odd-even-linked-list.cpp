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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode*oddh=head;
        ListNode*even=head->next;
        ListNode*evenh=even;
        
        while(even!=NULL && even->next!=NULL){
            oddh->next=even->next;
            oddh=oddh->next;
            even->next=oddh->next;
            even=even->next;
            
        }
        oddh->next=evenh;
        return head;
    }
};