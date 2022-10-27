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
        ListNode* tmp=new ListNode(-1);
        auto dummy=tmp;
        dummy->next=head;
        while(dummy->next && dummy->next->next){
            auto curr=dummy->next;
            auto nxt=curr->next;
            dummy->next=nxt;
            curr->next=nxt->next;
            nxt->next=curr;
            dummy=curr;
        }
        return tmp->next;
    }
};
// -1-->1-->2-->3-->4