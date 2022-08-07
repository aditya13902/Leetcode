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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto ptr1=headA;
        auto ptr2=headB;
        while(ptr1!=ptr2){
            if(ptr1){
                ptr1=ptr1->next;
            }
            else{
                ptr1=headB;
            }
            if(ptr2){
                ptr2=ptr2->next;
            }
            else{
                ptr2=headA;
            }
        }
        return ptr1;
    }
};

// x+y+z
// z+y+x