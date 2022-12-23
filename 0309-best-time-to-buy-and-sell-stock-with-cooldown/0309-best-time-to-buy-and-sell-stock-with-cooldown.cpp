class Solution {
public:
    
    int maxfunc(vector<int>& prices,int i,int f,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][f]!=-1) return dp[i][f];
        int ans=maxfunc(prices,i+1,f,dp);
        if(f){
            ans=max(ans,-prices[i]+maxfunc(prices,i+1,!f,dp));
        }
        else{
            ans=max(ans,prices[i]+maxfunc(prices,i+2,!f,dp));
        }
        return dp[i][f]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return maxfunc(prices,0,1,dp);
    }
};