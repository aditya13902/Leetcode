// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int>col;
    bool flag=true;
    void dfs(vector<int>adj[],int v,int num){
        if(col[v]!=0 && col[v]==-num){
            flag=false;
            return;
        }
        if(col[v]==num){
            return;
        }
        col[v]=num;
        for(auto ele:adj[v]){
            dfs(adj,ele,-num);
        }

    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    col.resize(V,0);
	    for(int i=0;i<V;i++){
	        if(col[i]==0){
	            dfs(adj,i,1);
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