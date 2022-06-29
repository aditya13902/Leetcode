class Node{
    
public:
    Node* links[26];
    bool flag=false;
    bool check(char ch){
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node){
        links[ch-'a']=node;
    }
    void end(){
        flag=true;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    // map<pair<string,int>,bool>mp;
    void addWord(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->check(word[i])){
                curr->set(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        curr->end();
    }
    bool helper(string& word,Node* curr,int idx){
        if(idx==word.size()){
            return curr->flag;
        }
        // if(mp.find({word,idx})!=mp.end()){
        //     return mp[{word,idx}];
        // }
        if(word[idx]!='.'){
            if(!curr->check(word[idx])){
                return false;
            }
            return helper(word,curr->get(word[idx]),idx+1);
        }
        else{
            int f=0;
            for(int i=0;i<26;i++){
                if(curr->links[i]!=NULL){
                    f|=helper(word,curr->links[i],idx+1);
                }
            }
            return f;
        }
    }
    bool search(string word) {
        Node* curr=root;
        return helper(word,curr,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */