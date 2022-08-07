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
    ListNode* rev(ListNode* head){
        if(!head ||!head->next) return head;
        auto nxt=rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return nxt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        auto ptr=head;
        ListNode* prev=NULL;
        while(ptr && cnt!=k){
            prev=ptr;
            ptr=ptr->next;
            cnt++;
        }
        if(cnt!=k) return head;
        prev->next=nullptr;
        auto node=rev(head);
        head->next=reverseKGroup(ptr,k);
        return node;
    }
};