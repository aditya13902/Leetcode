class Solution {
public:
    const int mod=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=high;i++){
            if(i>=zero){
                dp[i]=(dp[i]+dp[i-zero])%mod;
            }
            if(i>=one){
                dp[i]=(dp[i]+dp[i-one])%mod;
            }
        }
        for(int i=low;i<=high;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};