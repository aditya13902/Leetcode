//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU{
    vector<int>par;
    public:
    DSU(int n){
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=-1;
        }
    }
    bool set(int v){
        if(par[v]!=-1) return false;
        par[v]=v;
        return true;
    }
    int getParent(int v){
        if(par[v]==-1) return -1;
        if(par[v]==v) return v;
        
        return par[v]=getParent(par[v]);
    }
    bool Union(int a,int b){
        a=getParent(a);
        b=getParent(b);
        if(a==b || b==-1) return false;
        par[b]=a;
        return true;
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU dsu(n*m);
        vector<int>dx={1,0,-1,0};
        vector<int>dy={0,1,0,-1};
        int cnt=0;
        vector<int>ans;
        for(auto vec: operators){
            int x=vec[0];
            int y=vec[1];
            if(!dsu.set(x*m+y)){
                ans.push_back(cnt);
                continue;
            }
            cnt++;
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m){
                    if(dsu.Union(x*m+y,newx*m+newy)){
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends