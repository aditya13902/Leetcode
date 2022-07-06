// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int>dis;
    vector<int>vis;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        dis.resize(V,1e9);
        vis.resize(V,0);
        // vis[S]=1;
        set<pair<int,int>>st;
        st.insert({0,S});
        dis[S]=0;
        while(st.size()){
            auto curr=*st.begin();
            st.erase(st.begin());
            int curr_dist=curr.first;
            int curr_v=curr.second;
            if(vis[curr_v]){
                continue;
            }
            vis[curr_v]=1;
            for(auto ele:adj[curr_v]){
                if(dis[ele[0]]>curr_dist+ele[1]){
                    dis[ele[0]]=curr_dist+ele[1];
                    st.insert({dis[ele[0]],ele[0]});
                }
            }
        }
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends