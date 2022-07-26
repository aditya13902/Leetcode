// sample 827 ms submission
class Node {
public:
    int key, value;
    Node *prev = NULL;
    Node *next = NULL;
    Node(int key_ = -1, int value_ = -1) {
        value = value_;
        key = key_;
    }
};

class LRUCache {
    unordered_map<int,Node> cache;
    int cap;
    Node *front = NULL;
    Node *back = NULL;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void move_front(int key) {
        Node *curr = &cache[key];
        if(front && front == curr) return;
        
        // remove from node list
        if(cache.size() == 1) {
            back = curr;
            front = curr;
            
            return;
        } else if(curr->next && curr->prev) {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            curr->next = NULL;
            curr->prev = NULL;
        } else if(back && back == curr) {
            back = back->next;
            back->prev = NULL;
            
            curr->prev = NULL;
            curr->next = NULL;
        }
        
        // push front
        front->next = curr;
        curr->prev = front;
        front = curr;
    }
    
    int get(int key) {
        int val = -1;
        
        if(cache.count(key)) {
            val = cache[key].value;
            move_front(key);
        }
        
        return val;
    }
    
    void put(int key, int value) {
        Node* curr = &cache[key];
        curr->key = key;
        curr->value = value;
        
        move_front(key);
        
        if(cache.size() > cap) {
            //pop_back
            Node* temp = back;
            back = temp->next;
            back->prev = NULL;
            temp->next = NULL;
            cache.erase(temp->key);
        }
        
    }
};