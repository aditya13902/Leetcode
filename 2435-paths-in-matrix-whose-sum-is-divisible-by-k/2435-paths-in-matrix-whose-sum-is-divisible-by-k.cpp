// const int N=1e5;
const int mod=1e9+7;
class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int k,int i,int j,long long sum,vector<vector<vector<int>>>&dp){
        if(i==grid.size() || j==grid[0].size()) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            sum=(sum+grid[i][j])%k;
            return sum==0;
        }
        sum=(sum+grid[i][j])%k;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        
        int ans=0;
        ans=(ans+helper(grid,k,i+1,j,sum,dp))%mod;
        ans=(ans+helper(grid,k,i,j+1,sum,dp))%mod;
        return dp[i][j][sum]=ans;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        return helper(grid,k,0,0,0,dp);
    }
};