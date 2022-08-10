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
class cmp{
public:
    bool operator()(ListNode* head1,ListNode* head2){
        return head1->val>head2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto node:lists){
            if(!node) continue;
            pq.push(node);
        }
        ListNode* dummy=new ListNode(-1);
        auto ptr=dummy;
        while(pq.size()){
            auto head=pq.top();
            pq.pop();
            ptr->next=head;
            ptr=ptr->next;
            if(head->next){
                pq.push(head->next);
            }
        }
        return dummy->next;
    }
};