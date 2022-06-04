class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&piles,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=piles[i]+min(helper(piles,i+2,j),helper(piles,i+1,j-1));
        int b=piles[j]+min(helper(piles,i+1,j-1),helper(piles,i,j-2));
        return dp[i][j]=max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return helper(piles,0,n-1);
    }
};