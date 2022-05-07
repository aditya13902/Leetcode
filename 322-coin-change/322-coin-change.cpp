class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto ele:coins){
                if(i-ele>=0 && dp[i-ele]!=INT_MAX){
                    dp[i]=min(1+dp[i-ele],dp[i]);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};