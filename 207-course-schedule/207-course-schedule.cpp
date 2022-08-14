class Solution {
public:
    vector<int>vis;
    bool dfs(vector<vector<int>>&adj,int v,unordered_set<int>&st){
        if(st.find(v)!=st.end()) return false;
        if(vis[v]) return true;
        st.insert(v);
        vis[v]=1;
        for(auto ele:adj[v]){
            if(!dfs(adj,ele,st)) return false;
        }
        st.erase(v);
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vis.resize(n,0);
        vector<vector<int>>adj(n);
        for(auto vec:prereq){
            adj[vec[0]].push_back(vec[1]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            unordered_set<int>st;
            int flag=dfs(adj,i,st);
            if(!flag) return false;
        }
        return true;
    }
};