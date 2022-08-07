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
        if(!node || !node->next) return node;
        auto nxt=rev(node->next);
        node->next->next=node;
        node->next=NULL;
        return nxt;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* runner=dummy;
        ListNode* walker=dummy;
        while(runner && runner->next){
            runner=runner->next->next;
            walker=walker->next;
        }
        walker->next=rev(walker->next);
        auto ptr1=dummy->next;
        auto ptr2=walker->next;
        while(ptr2){
            // cout<<ptr1->val<< "-"<<ptr2->val<<endl;
            if(ptr2->val!=ptr1->val) return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};
// 1 2 3 4 5