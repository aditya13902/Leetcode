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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr=head;
        ListNode* first=NULL;
        int cnt=0;
        while(ptr){
            cnt++;
            if(cnt==k){
                first=ptr;
                ptr=ptr->next;
                break;
            }
            ptr=ptr->next;
        }
        ListNode*tmp=head;
        while(ptr){
            ptr=ptr->next;
            tmp=tmp->next;
        }
        swap(first->val,tmp->val);
        return head;
    }
};