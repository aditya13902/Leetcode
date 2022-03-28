class Solution {
public:
    vector<int>vis;
    int n;
    vector<vector<int>>adj;
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& adj,int s,vector<int>&subans){
        if(s==n-1){
            ans.push_back(subans);
            return;
        }
        // if(vis[s]==1){
        //     return;
        // }
        vis[s]=1;
        for(auto ele:adj[s]){
            subans.push_back(ele);
            dfs(adj,ele,subans);
            subans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        n=adj.size();
        vis.resize(n,0);
        // if(n==0){
        //     return ans;
        // }
        vector<int>subans;
        if(n>0){
            subans.push_back(0);
            dfs(adj,0,subans);
        }
        return ans;
    }
};