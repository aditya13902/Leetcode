class Solution {
public:
    vector<int>vis;
    void dfs(vector<vector<int>>&adj,int i){
        if(vis[i]){
            return;
        }
        vis[i]=1;
        for(auto ele:adj[i]){
            dfs(adj,ele);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        vis.resize(isConnected.size(),0);
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i]==0){
                dfs(adj,i);
                cnt++;
            }
        }
        return cnt;
    }
};