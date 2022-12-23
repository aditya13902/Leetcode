class Solution {
public:
    // int maxfunc(vector<int>& prices,int i,int f,vector<vector<int>>&dp){
    //     if(i>=prices.size()) return 0;
    //     if(dp[i][f]!=-1) return dp[i][f];
    //     int ans=maxfunc(prices,i+1,f,dp);
    //     if(f){
    //         ans=max(ans,-prices[i]+maxfunc(prices,i+1,!f,dp));
    //     }
    //     else{
    //         ans=max(ans,prices[i]+maxfunc(prices,i+2,!f,dp));
    //     }
    //     return dp[i][f]=ans;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int f=0;f<2;f++){
                dp[i][f]=dp[i+1][f];
                if(f){
                    dp[i][f]=max(dp[i][f],-prices[i]+dp[i+1][!f]);
                }
                else{
                    dp[i][f]=max(dp[i][f],prices[i]+dp[i+2][!f]);
                }
            }
        }
        return dp[0][1];
    }
};