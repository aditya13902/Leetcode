class Solution {
public:
    vector<int>vis;
    bool dfs(vector<vector<int>>&graph,int v,int f){
        if(vis[v]!=0){
            return vis[v]==f;
        }
        vis[v]=f;
        for(auto ele:graph[v]){
            if(!dfs(graph,ele,-f)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!dfs(graph,i,1)) return false;
            }
        }
        return true;
    }
};