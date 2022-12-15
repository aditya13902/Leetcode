class Solution {
public:
    long long mod=1e9+7;
    long long add(int a,int b){
        return (a+b)%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long curr=0;
        vector<int>dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            long long npeep=(i-delay>0)?dp[i-delay]:0;
            long long fpeep=(i-forget>0)?dp[i-forget]:0;
            dp[i]=add(curr,(npeep-fpeep+mod)%mod);
            curr=dp[i];
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=add(ans,dp[i]);
        }
        return ans;
    }
};