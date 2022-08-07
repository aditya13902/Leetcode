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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        auto dummy=new ListNode(-1);
        auto ptr=dummy;
        while(l1 && l2){
            c+=l1->val+l2->val;
            ptr->next=new ListNode(c%10);
            c/=10;
            l1=l1->next;
            l2=l2->next;
            ptr=ptr->next;
        }
        while(l1){
            c+=l1->val;
            ptr->next=new ListNode(c%10);
            c/=10;
            l1=l1->next;
            ptr=ptr->next;
        }
        while(l2){
            c+=l2->val;
            ptr->next=new ListNode(c%10);
            c/=10;
            l2=l2->next;
            ptr=ptr->next;
        }
        if(c){
            ptr->next=new ListNode(c%10);
            c=c/10;
        }
        return dummy->next;
    }
};