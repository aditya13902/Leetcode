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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(ptr1 && ptr2){
            if(ptr1->val>ptr2->val){
                head->next=ptr2;
                ptr2=ptr2->next;
            }
            else{
                head->next=ptr1;
                ptr1=ptr1->next;
            }
            head=head->next;
        }
        while(ptr1){
            head->next=ptr1;
            head=head->next;
            ptr1=ptr1->next;
        }
        while(ptr2){
            head->next=ptr2;
            head=head->next;
            ptr2=ptr2->next;
        }
        return dummy->next;
    }
};