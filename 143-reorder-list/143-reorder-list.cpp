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
    ListNode* rev(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        auto runner=dummy;
        auto walker=dummy;
        dummy->next=head;
        while(runner && runner->next){
            runner=runner->next->next;
            walker=walker->next;
        }
        walker->next=rev(walker->next);
        auto ptr1=head;
        auto ptr2=walker->next;
        walker->next=NULL;
        dummy=new ListNode(-1);
        auto ans=dummy;
        while(ptr1 && ptr2){
            dummy->next=ptr1;
            ptr1=ptr1->next;
            dummy=dummy->next;
            dummy->next=ptr2;
            ptr2=ptr2->next;
            dummy=dummy->next;

        }
        if(ptr1){
                dummy->next=ptr1;
                ptr1=ptr1->next;
                dummy=dummy->next;
        }
        if(ptr2){
                dummy->next=ptr2;
                ptr2=ptr2->next;
                dummy=dummy->next;
        }
        head= ans->next;
    }
};