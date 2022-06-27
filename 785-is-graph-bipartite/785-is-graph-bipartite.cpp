class Solution {
public:
    vector<int>vis;
    int f=1;
    void dfs(vector<vector<int>>&adj,int v,int col){
        if(vis[v]!=0){
            if(vis[v]!=col){
                f=0;
            }
            // f=0;
            return;
        }
        vis[v]=col;
        for(auto ele:adj[v]){
            dfs(adj,ele,-col);
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vis.resize(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(adj,i,1);
            }
        }
        return f;
    }
};