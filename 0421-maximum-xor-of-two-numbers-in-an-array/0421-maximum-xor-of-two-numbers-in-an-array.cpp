class Node{
public:
    Node* links[2];
    Node(){
        for(int i=0;i<2;i++){
             links[i]=NULL;
        }
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void add(int n){
        auto curr=root;
        for(int i=31;i>=0;i--){
            int idx=(n>>i)&1;
            if(curr->links[idx]==NULL){
                curr->links[idx]=new Node();
            }
            curr=curr->links[idx];
        }
    }
    int find_xor(int n){
        auto curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int idx=(n>>i)&1;
            if(curr->links[!idx]!=NULL){
                curr=curr->links[!idx];
                ans|=(1<<i);
            }
            else{
                curr=curr->links[idx];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto ele:nums){
            t.add(ele);
        }
        int ans=0;
        for(auto ele:nums){
            ans=max(ans,t.find_xor(ele));
        }
        return ans;
    }
};