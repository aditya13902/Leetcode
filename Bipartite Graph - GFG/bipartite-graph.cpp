// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int>color;
    bool flag=true;
    void dfs(vector<int>adj[],int node,int col){
        if(color[node]!=-1 && color[node]!=col){
            flag=false;
            return;
        }
        if(color[node]==col){
            return;
        }
        color[node]=col;
        for(auto ele:adj[node]){
            dfs(adj,ele,col xor 1);
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   // int n=adj.size();
	    color.resize(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            dfs(adj,i,0);
	        }
	    }
	    return flag;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends