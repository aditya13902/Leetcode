//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        set<vector<int>>st;
        st.insert({0,0,0});
        dis[0][0]=0;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        while(st.size()){
            auto it=*(st.begin());
            st.erase(st.begin());
            int d=it[0];
            int x=it[1];
            int y=it[2];
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && dis[newx][newy]>max(abs(grid[x][y]-grid[newx][newy]),d)){
                    dis[newx][newy]=max(abs(grid[x][y]-grid[newx][newy]),d);
                    st.insert({dis[newx][newy],newx,newy});
                }
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends