class Solution {
public:
    vector<int>dp;
    bool dfs(vector<vector<int>>&graph,int v,vector<int>&vis){
        if(vis[v]){
            return false;
        }
        if(dp[v]!=-1){
            return dp[v];
        }
        vis[v]=1;
        for(auto ele:graph[v]){
            if(dfs(graph,ele,vis)==false){
                return dp[v]=false;
            }
        }
        vis[v]=0;
        return dp[v]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vec;
        vector<int>vis(graph.size(),0);
        dp.resize(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            int cnt=0;
            int ans=dfs(graph,i,vis);
            if(ans){
                vec.push_back(i);
            }
        }
        return vec;
    }
};