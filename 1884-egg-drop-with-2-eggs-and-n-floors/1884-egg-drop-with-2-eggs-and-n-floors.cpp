class Solution {
public:
    vector<vector<int>>dp;
    int helper(int n,int egg){
        if(egg==0){
            return n;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][egg]!=-1) return dp[n][egg];
        int ans=n;
        for(int i=1;i<=n;i++){
            int subans=1+max(helper(i-1,egg-1),helper(n-i,egg));
            ans=min(ans,subans);
        }
        return dp[n][egg]=ans;
    }
    int twoEggDrop(int n) {
        dp.resize(n+1,vector<int>(2,-1));
        return helper(n,1);
    }
};