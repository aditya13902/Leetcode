class Solution {
public:
    vector<vector<int>>dp;
    int helper(int n,int e){
        if(n==1) return 1;
        if(e==0) return n;
        int ans=1e8;
        if(dp[n][e]!=-1) return dp[n][e];
        for(int i=1;i<=n;i++){
            ans=min(ans,1+max(helper(i-1,e-1),helper(n-i,e)));
        }
        return dp[n][e]=ans;
    }
    int twoEggDrop(int n) {
        dp.resize(n+1,vector<int>(2,-1));
        return helper(n,1);
    }
};