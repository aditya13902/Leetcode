class Solution {
public:
    int helper(vector<int>& prices,int idx,int flag,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        if(flag){
            return dp[idx][flag]= max(-prices[idx]+helper(prices,idx+1,!flag,dp),helper(prices,idx+1,flag,dp));
        }
        else{
            return dp[idx][flag]= max(prices[idx]+helper(prices,idx+2,!flag,dp),helper(prices,idx+1,flag,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,1,dp);
    }
};