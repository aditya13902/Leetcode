/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }
        Node* ptr=head;
        Node* nxt;
        while(ptr){
            nxt=ptr->next;
            ptr->next=new Node(ptr->val);
            ptr->next->next=nxt;
            ptr=nxt;
        }
        ptr=head;
        while(ptr){
            if(ptr->random){
                ptr->next->random=ptr->random->next;
            }
            
            ptr=ptr->next->next;
        }
        Node* original=head;
        
        // A'->B'->C'
        Node* clone=head->next;
        
        // Result is used for returning
        Node* result=head->next;
        // 3rd Pass
        
        while(original!=NULL)
        {
            original->next=original->next->next;
            clone->next= (clone->next)?(clone->next->next):NULL;
            
            original=original->next;
            clone=clone->next;
        }
        
        return result;
    }
};