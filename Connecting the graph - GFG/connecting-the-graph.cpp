//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DSU{
    vector<int>par;
    public:
    DSU(int n){
        par.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int getP(int a){
        if(par[a]==a) return a;
        return par[a]=getP(par[a]);
    }
    void Union(int a,int b){
        a=getP(a);
        b=getP(b);
        par[b]=a;
    }
    int count(){
        int cnt=0;
        for(int i=0;i<par.size();i++){
            if(par[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge){
        // code here
        DSU d(n);
        for(auto ele:edge){
            d.Union(ele[0],ele[1]);
        }
        if(edge.size()<(n-1)){
            return -1;
        }
        else{
            return d.count()-1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<vector<int>>adj;
        
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
            
            Solution Obj;
            cout<<Obj.Solve(n,adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends