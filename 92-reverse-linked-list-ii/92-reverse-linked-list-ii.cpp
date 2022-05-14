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
    ListNode* rev(ListNode* node){
        if(!node || !node->next){
            return node;
        }
        auto ptr=rev(node->next);
        node->next->next=node;
        node->next=NULL;
        return ptr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr=head;
        int cnt=1;
        ListNode* rgt=NULL;
        while(ptr){
            if(cnt==right){
                rgt=ptr->next;
                ptr->next=NULL;
            }
            cnt++;
            ptr=ptr->next;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ptr=dummy;
        cnt=1;
        ListNode* ptr2;
        while(ptr){
            if(cnt==left){
                ptr2=ptr->next;
                ptr->next=rev(ptr->next);
            }
            cnt++;
            ptr=ptr->next;
        }
        ptr2->next=rgt;
        return dummy->next;
    }
};