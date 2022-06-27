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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto vec:dislikes){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vis.resize(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(adj,i,1);
            }
        }
        return f;
        
    }
};