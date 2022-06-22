class Solution {
public:
    vector<vector<int>>vis;
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1' || vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vis.resize(r,vector<int>(c,0));
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};