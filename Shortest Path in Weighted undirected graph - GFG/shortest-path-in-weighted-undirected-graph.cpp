//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<vector<int>>>adj(n+1);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>dis(n+1,1e9);
        dis[1]=0;
        vector<int>par(n+1,-1);
        set<pair<int,int>>st;
        st.insert({0,1});
        while(st.size()){
            auto curr=*(st.begin());
            st.erase(st.begin());
            int v=curr.second;
            int d=curr.first;
            for(auto ele:adj[v]){
                if(dis[ele[0]]>d+ele[1]){
                    dis[ele[0]]=d+ele[1];
                    st.insert({d+ele[1],ele[0]});
                    par[ele[0]]=v;
                }
            }
        }
        vector<int>ans;
        if(par[n]==-1) return {-1};
        int v=n;
        while(v!=-1){
            ans.push_back(v);
            v=par[v];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends