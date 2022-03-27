class Solution {
public:
    vector<int>vis;
    vector<vector<int>>adj;
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vis.resize(n+1,0);
        adj.resize(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vis[edges[i][0]]++;
            vis[edges[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==n-1){
                return i;
            }
        }
        return -1;
        
        
    }
};