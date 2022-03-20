class Solution {
public:
    vector<vector<int>>vis;
    void dfs(vector<vector<int>>&grid,int i,int j,int &subans){
        if(i<0 || j<0 ||i>=grid.size() ||j>=grid[0].size() || grid[i][j]==0 || vis[i][j]){
            return;
        }
        subans++;
        vis[i][j]=1;
        dfs(grid,i+1,j,subans);
        dfs(grid,i,j+1,subans);
        dfs(grid,i-1,j,subans);
        dfs(grid,i,j-1,subans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vis.resize(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int subans=0;
                    dfs(grid,i,j,subans);
                    ans=max(subans,ans);
                }
            }
        }
        return ans;
    }
};