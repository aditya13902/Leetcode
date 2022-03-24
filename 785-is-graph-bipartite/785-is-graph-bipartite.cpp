class Solution {
public:
    vector<int>color;
    vector<int>vis;
    bool flag;
    void dfs(vector<vector<int>>&graph,int u,int curr){
        if(color[u]!=-1 && color[u]!=curr){
            flag=false;
            return;
        }
        color[u]=curr;
        if(vis[u]){
            return;
        }
        vis[u]=1;
        for(auto ele:graph[u]){
            dfs(graph,ele,curr xor 1);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.resize(n,-1);
        vis.resize(n,0);
        flag=true;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(graph,i,0);
            }
        }
        return flag;
    }
};