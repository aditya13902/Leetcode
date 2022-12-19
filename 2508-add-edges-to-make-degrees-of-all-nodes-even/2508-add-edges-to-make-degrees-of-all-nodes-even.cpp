class Solution {
public:
    bool check(vector<vector<int>>&adj,int a,int b){
        int f=1;
        for(auto ele:adj[a]){
            if(ele==b){
                f=0;
            }
        }
        if(f) return true;
        else return false;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        // for(int i=1;i<=n;i++) adj[i].push_back(i);
        for(auto ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int>odd;
        for(int i=1;i<=n;i++){
            if((adj[i].size())%2) odd.push_back(i);
        }
        if(odd.size()==0) return true;
        if(odd.size()==2){
            int v1=odd[0];
            int v2=odd[1];
            int f=1;
            for(auto ele:adj[v1]){
                if(ele==v2){
                    f=0;
                }
            }
            if(f){
                return true;
            }
            else{
                cout<<"yeahh"<<endl;
                cout<<v1<<" "<<v2<<endl;
                unordered_set<int>st;
                for(auto ele:adj[v1]){
                    st.insert(ele);
                }
                for(auto ele:adj[v2]){
                    st.insert(ele);
                }
                for(int i=1;i<=n;i++){
                    if(st.find(i)==st.end()) return true;
                }
                return false;
            }
        }
        else if(odd.size()==4){
            int v1=odd[0];
            int v2=odd[1];
            int v3=odd[2];
            int v4=odd[3];
            return (check(adj,v1,v2) and check(adj,v3,v4)) || (check(adj,v1,v3) and check(adj,v2,v4)) || (check(adj,v1,v4) and check(adj,v2,v3));
            
        }
        else{
             return false;
        }
    }
};