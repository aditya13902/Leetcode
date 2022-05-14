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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        auto ptr=head;
        int cnt=1;
        while(ptr->next){
            ptr=ptr->next;
            cnt++;
        }
        if(k%cnt==0){
            return head;
        }
        k=k%cnt;
        ptr->next=head;
        while(cnt!=k){
            ptr=ptr->next;
            cnt--;
        }
        auto node=ptr->next;
        ptr->next=NULL;
        return node;
        
    }
};