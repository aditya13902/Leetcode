class Node{
public:
    Node* links[26];
    bool end=false;

    
};
class Trie {
private:
    Node* root;
public:
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(auto ch:word){
            if(curr->links[ch-'a']==NULL){
                curr->links[ch-'a']=new Node();
            }
            curr=curr->links[ch-'a'];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(auto ch:word){
            if(curr->links[ch-'a']==NULL) return false;
            curr=curr->links[ch-'a'];
        }
        // cout<<curr->end<<endl;
        return curr->end;
    }
    
    bool startsWith(string word) {
        Node* curr=root;
        for(auto ch:word){
            if(curr->links[ch-'a']==NULL) return false;
            curr=curr->links[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */