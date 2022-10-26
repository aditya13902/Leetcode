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
    ListNode* rev(ListNode* head,int k){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr && k){
            auto nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            k--;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        auto tmp=head;
        while(tmp && cnt<k){
            cnt++;
            tmp=tmp->next;
        }
        if(cnt<k){
            return head;
        }
        auto node=rev(head,k);
        head->next=reverseKGroup(tmp,k);
        return node;
    }
};