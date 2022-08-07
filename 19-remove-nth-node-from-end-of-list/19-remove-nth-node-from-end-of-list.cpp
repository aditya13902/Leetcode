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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* fast=dummy;
        int cnt=0;
        while(cnt!=n && fast){
            fast=fast->next;
            cnt++;
        }
        if(cnt!=n) return dummy->next;
        auto slow=dummy;
        ListNode* prev=NULL;
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev==NULL) return NULL;
        prev->next=slow->next;
        return dummy->next;
    }
};