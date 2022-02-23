/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        } 
        Node* copy=new Node(node->val);
        mp[node]=copy;
        queue<Node*>q;
        q.push(node);
        while(q.size()){
            Node* curr=q.front();
            q.pop();
            for(auto ptr:curr->neighbors){
                if(mp.find(ptr)==mp.end()){
                    Node* currnode=new Node(ptr->val);
                    mp[ptr]=currnode;
                    q.push(ptr);
                }
                mp[curr]->neighbors.push_back(mp[ptr]);
            }
            
        }
        return copy;
    }
};