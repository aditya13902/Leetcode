class Node{
private:
    Node* links[26];
    bool flag=false;
public:
    bool check(char ch){
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool checkend(){
        return flag;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->check(word[i])){
                curr->set(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        curr->setend();
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->check(word[i])){
                return false;
            }
            curr=curr->get(word[i]);
        }
        return curr->checkend();
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->check(prefix[i])){
                return false;
            }
            curr=curr->get(prefix[i]);
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