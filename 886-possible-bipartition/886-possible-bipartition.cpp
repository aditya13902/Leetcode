class Solution {
public:
    vector<int>color;
    vector<int>vis;
    bool flag;
    vector<vector<int>>adj;
    void dfs(int u,int curr){
        if(color[u]!=-1 && color[u]!=curr){
            flag=false;
            return;
        }
        color[u]=curr;
        if(vis[u]){
            return;
        }
        vis[u]=1;
        for(auto ele:adj[u]){
            dfs(ele,curr xor 1);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n+1,-1);
        vis.resize(n+1,0);
        flag=true;
        adj.resize(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,0);
            }
        }
        return flag;
    }
};