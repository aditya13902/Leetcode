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
    ListNode *detectCycle(ListNode *head) {
        auto ptr1=head;
        auto ptr2=head;
        while(ptr2 && ptr2->next){
            ptr2=ptr2->next->next;
            ptr1=ptr1->next;
            if(ptr1==ptr2) break;
        }
        if(!ptr2 || !ptr2->next) return NULL;
        // cout<<ptr1->val<<"-"<<ptr2->val<<endl;
        ptr2=head;
        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr2;
    }
};