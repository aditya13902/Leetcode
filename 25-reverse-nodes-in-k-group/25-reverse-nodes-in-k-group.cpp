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
    ListNode* rev(ListNode* ptr,int cnt){
        auto curr=ptr;
        ListNode* prev=NULL;
        while(curr && cnt){
            auto nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt--;
        }
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        auto curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr!=NULL && cnt!=k){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(cnt!=k) return head;
        
        auto new_head=rev(head,k);
        head->next=reverseKGroup(curr,k);
        return new_head;
    }
};