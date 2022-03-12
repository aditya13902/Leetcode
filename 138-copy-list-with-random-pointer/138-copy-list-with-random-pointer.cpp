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
        Node*ptr=head;
        while(ptr){
            mp[ptr]=new Node(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        Node* dummy=mp[head];
        while(ptr){
            dummy->next=mp[ptr->next];
            dummy->random=mp[ptr->random];
            ptr=ptr->next;
            dummy=dummy->next;
        }
        return mp[head];
    }
};