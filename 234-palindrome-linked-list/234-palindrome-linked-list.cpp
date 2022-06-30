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
        ListNode* tmp=rev(node->next);
        node->next->next=node;
        node->next=NULL;
        return tmp;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* walker=dummy;
        ListNode* runner=dummy;
        while(runner && runner->next){
            runner=runner->next->next;
            walker=walker->next;
        }
        walker->next=rev(walker->next);
        ListNode* ptr1=dummy->next;
        ListNode*ptr2=walker->next;
        // cout<<ptr1->val<<" "<<ptr1->val<<endl;
        while(ptr2){
            if(ptr1->val!=ptr2->val){
                return false;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
        
    }
};
 //              r
 // -1 1 2 3 2 1
 //        w