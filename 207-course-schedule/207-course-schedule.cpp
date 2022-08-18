class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    bool dfs(int v,unordered_set<int>&st){
        if(st.find(v)!=st.end()) return false;
        if(vis[v]) return true;
        vis[v]=1;
        st.insert(v);
        for(auto ele:adj[v]){
            if(!dfs(ele,st)) return false;
        }
        st.erase(v);
        return true;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        adj.resize(num);
        vis.resize(num,0);
        for(auto vec:pre){
            adj[vec[0]].push_back(vec[1]);
        }
        for(int i=0;i<num;i++){
            if(!vis[i]){
                unordered_set<int>st;
                if(!dfs(i,st)) return false;
            }
        }
        return true;
    }
};