// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<int>vis;
    int flag=0;
    void dfs(vector<int>adj[],int curr,int par){
        if(vis[curr]==1){
            return;
        }
        vis[curr]=1;
        for(auto ele:adj[curr]){
            if(vis[ele]==1 && ele!=par){
                flag=1;
                return;
            }
            if(ele!=par){
                dfs(adj,ele,curr);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vis.resize(V,0);
        for(int i=0;i<V;i++){
            dfs(adj,i,-1);
        }
        return flag;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends