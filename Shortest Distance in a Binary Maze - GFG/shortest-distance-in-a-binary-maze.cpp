//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        queue<vector<int>>q;
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        q.push({source.first,source.second,0});
        dis[source.first][source.second]=0;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        while(q.size()){
            auto curr=q.front();
            q.pop();
            if(curr[0]==destination.first && curr[1]==destination.second){
                return curr[2];
            }
            for(int i=0;i<4;i++){
                int x=curr[0]+dx[i];
                int y=curr[1]+dy[i];
                if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && dis[x][y]>curr[2]+1 && grid[x][y]==1){
                    dis[x][y]=1+curr[2];
                    q.push({x,y,curr[2]+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends