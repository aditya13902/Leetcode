class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int helper(vector<vector<int>>& grid,int r1,int c1,int c2){
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        int ans=grid[r1][c1];
        if(r1!=r2){
            ans+=grid[r2][c2];
        }
        int pick =max(helper(grid,r1+1,c1,c2+1),helper(grid,r1+1,c1,c2));
        pick=max(pick,helper(grid,r1,c1+1,c2+1));
        pick=max(pick,helper(grid,r1,c1+1,c2));
        return dp[r1][c1][c2]=pick+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        dp.resize(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,helper(grid,0,0,0));
    }
};