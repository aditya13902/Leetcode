class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>>dp;
    long long helper(int n,int k){
        if(n==k) return 1;
        if(n==0 || k==0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        return dp[n][k]=(helper(n-1,k-1)+(n-1)*1LL*helper(n-1,k))%mod;
    }
    int rearrangeSticks(int n, int k) {
        dp.resize(n+1,vector<int>(k+1,-1));
        return helper(n,k);
    }
};