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
    bool hasCycle(ListNode *head) {
        ListNode* runner=head;
        ListNode* walker=head;
        while(runner && runner->next){
            runner=runner->next->next;
            walker=walker->next;
            if(runner==walker){
                return true;
            }
        }
        return false;
    }
};