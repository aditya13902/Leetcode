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
        unordered_map<Node*,Node*>mp;
        Node* ptr=head;
        Node* dummy=new Node(-1);
        Node* node=dummy;
        while(ptr!=NULL){
            node->next=new Node(ptr->val);
            mp[ptr]=node->next;
            node=node->next;
            ptr=ptr->next;
        }
        ptr=head;
        // node=dummy;
        while(ptr!=NULL){
            if(ptr->random){
                mp[ptr]->random=mp[ptr->random];
            }
            ptr=ptr->next;
        }
        return dummy->next;
    }
};