class Node{
public:
    Node* links[26];
    bool end;
    Node(){
        end=false;
        for(int i=0;i<26;i++) links[i]=NULL;
    }
    
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        auto tmp=root;
        for(int i=0;i<s.size();i++){
            if(tmp->links[s[i]-'a']){
                tmp=tmp->links[s[i]-'a'];
            }
            else{
                tmp->links[s[i]-'a']=new Node();
                tmp=tmp->links[s[i]-'a'];
            }
        }
        tmp->end=true;
    }
};

class Solution {
private:
    vector<vector<int>>vis;
    set<string>ans;
    void helper(vector<vector<char>>&board,int i,int j,Node* node,string &s){
        if(node->end){
            ans.insert(s);
            node->end=false;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]) return;
        if(!node->links[board[i][j]-'a']){
            return;
        }
        node=node->links[board[i][j]-'a'];
        vis[i][j]=1;
        s.push_back(board[i][j]);
        helper(board,i+1,j,node,s);
        helper(board,i,j+1,node,s);
        helper(board,i,j-1,node,s);
        helper(board,i-1,j,node,s);
        s.pop_back();
        vis[i][j]=0;
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto str:words) t.insert(str);
        
        vis.resize(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                Node* node=t.root;
                string s="";
                helper(board,i,j,node,s);
            }
        }
        vector<string>vec;
        for(auto ele:ans) vec.push_back(ele);
        
        return vec;
    }
};