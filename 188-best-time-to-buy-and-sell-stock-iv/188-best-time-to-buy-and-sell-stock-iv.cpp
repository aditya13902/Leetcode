class Solution {
public:
    
    int func(vector<int>&prices,int idx,int k,int f,vector<vector<vector<int>>>&dp){
        if(k==0 || idx==prices.size()) return 0;
        if(dp[idx][k][f]!=-1){
            return dp[idx][k][f];
        }
        if(f){
            return dp[idx][k][f]=max(func(prices,idx+1,k,f,dp),-prices[idx]+func(prices,idx+1,k,!f,dp));
        }
        else{
            return dp[idx][k][f]=max(func(prices,idx+1,k,f,dp),prices[idx]+func(prices,idx+1,k-1,!f,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return func(prices,0,k,1,dp);
    }
};