class Solution {
public:
    
    // int func(vector<int>&prices,int idx,int k,int f,vector<vector<vector<int>>>&dp){
    //     if(k==0 || idx==prices.size()) return 0;
    //     if(dp[idx][k][f]!=-1){
    //         return dp[idx][k][f];
    //     }
    //     if(f){
    //         return dp[idx][k][f]=max(func(prices,idx+1,k,f,dp),-prices[idx]+func(prices,idx+1,k,!f,dp));
    //     }
    //     else{
    //         return dp[idx][k][f]=max(func(prices,idx+1,k,f,dp),prices[idx]+func(prices,idx+1,k-1,!f,dp));
    //     }
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        // return func(prices,0,k,1,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int f=0;f<=1;f++){
                    if(f){
                        dp[i][j][f]=max(dp[i+1][j][f],-prices[i]+dp[i+1][j][!f]);
                    }
                    else{
                        dp[i][j][f]=max(dp[i+1][j][f],prices[i]+dp[i+1][j-1][!f]);
                    }
                }
            }
        }
        return dp[0][k][1];
    }
};