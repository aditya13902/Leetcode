class Node{
public:
    Node* links[26];
    bool end;
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
        end=false;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string str){
        auto curr=root;
        for(int i=0;i<str.size();i++){
            // if(curr[i])
            int idx=str[i]-'a';
            if(curr->links[idx]){
                curr=curr->links[idx];
            }
            else{
                curr->links[idx]=new Node();
                curr=curr->links[idx];
            }
        }
        curr->end=true;
    }
    string search(string str){
        auto curr=root;
        string word="";
        for(int i=0;i<str.size();i++){
            int idx=str[i]-'a';
            if(curr->end){
                break;
            }
            word+=str[i];
            if(curr->links[idx]){
                curr=curr->links[idx];
            }
            else{
                return "";
            }
        }
        cout<<word<<endl;
        if(curr->end){
            
            return word;
        }
        return "";
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        Trie t;
        for(auto str:dictionary){
            t.insert(str);
        }
        // sentence+=' ';
        string str="";
        for(char ch:sentence){
            if(ch==' '){
                auto curr=t.search(str);
                // cout<<curr<<endl;
                if(curr!=""){
                    ans+=curr;
                    ans+=' ';
                }
                else{
                    ans+=str;
                    ans+=' ';
                }
                str="";
            }
            else{
                str+=ch;
            }
        }
        auto curr=t.search(str);
        if(curr!=""){
            ans+=curr;
            // ans+=' ';
            str="";
        }
        else{
            ans+=str;
            // ans+=' ';
        }
        return ans;
    }
};