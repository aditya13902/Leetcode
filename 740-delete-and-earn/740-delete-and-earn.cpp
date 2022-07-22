class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=0;
        
        for(auto ele:nums) mx=max(ele,mx);
        vector<int>sum(mx+1,0);
        for(auto ele:nums) sum[ele]+=ele;
        vector<int>dp(mx+1,0);
        dp[1]=sum[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],sum[i]+dp[i-2]);
        }
        return dp[mx];
    }
};