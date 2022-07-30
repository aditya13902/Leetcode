class Solution {
public:
    vector<int>col;
    bool dfs(vector<vector<int>>graph,int v,int color){
        if(col[v]!=0) return col[v]==color;
        col[v]=color;
        for(auto ele:graph[v]){
            if(!dfs(graph,ele,-color)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        col.resize(n,0);
        for(int i=0;i<n;i++){
            if(col[i]==0){
                if(!dfs(graph,i,1)) return false;
            }
        }
        return true;
    }
};