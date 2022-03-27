class Solution {
public:
    vector<int>vis;
    vector<vector<int>>adj;
    void dfs(int s){
        if(vis[s]){
            return;
        }
        vis[s]=1;
        for(auto ele:adj[s]){
            dfs(ele);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int e) {
        vis.resize(n,0);
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(s);
        if(vis[e]){
            return true;
        }
        return false;
    }
};