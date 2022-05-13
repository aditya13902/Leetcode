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
    bool isPalindrome(ListNode* head) {
        ListNode* walker=head;
        ListNode* runner=head->next;
        while(runner && runner->next){
            walker=walker->next;
            runner=runner->next->next;
        }
        walker->next=rev(walker->next);
        walker=walker->next;
        while(walker){
            if(walker->val!=head->val){
                return false;
            }
            walker=walker->next;
            head=head->next;
        }
        return true;
        
    }
};
