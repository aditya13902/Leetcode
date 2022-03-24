class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&color,int c,int node){
        if(color[node]!=-1){
            return color[node]==c;
        }
        color[node]=c;
        for(auto ele:graph[node]){
            if(!dfs(graph,color,c xor 1,ele)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1 && !dfs(graph,color,1,i)){
                return false;
            }
        }
        return true;
    }
};