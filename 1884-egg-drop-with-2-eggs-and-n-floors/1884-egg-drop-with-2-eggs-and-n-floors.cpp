class Solution {
public:
    vector<vector<int>>dp;
    int helper(int n,int k){
        if(n==0)return 0;
        if(k==0) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        int ans=n;
        for(int i=1;i<=n;i++){
            ans=min(ans,1+max(helper(i-1,k-1),helper(n-i,k)));
        }
        return dp[n][k]=ans;
    }
    int twoEggDrop(int n) {
        dp.resize(n+1,vector<int>(2,-1));
        return helper(n,1);
    }
};