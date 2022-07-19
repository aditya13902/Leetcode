// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head==NULL){
//             return NULL;
//         }
//         ListNode* walker=head;
//         ListNode* runner=head;
//         while(runner->next!=NULL && runner->next->next!=NULL && runner!=walker){
//             runner=runner->next->next;
//             walker=walker->next;
//         }
//         if(runner->next==NULL || runner->next->next==NULL){
//             return NULL;
//         }
//         walker=head;
//         while(walker!=runner){
//             walker=walker->next;
//             runner=runner->next;
//         }
//         return runner;
//     }
// };
class Solution {
public:
    
// Distance traveled by slow when they meet: L1+L2
// Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

// 2(L1+L2) = L1+L2+x+L2
// 2L1 + 2L2 = L1+2L2+x
// => x = L1

// so we need to move L1 steps from the current meeting point to reach the entry point of the cycle.
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        if(head==0)
            return NULL;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                fast=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return NULL;
        
    }
};