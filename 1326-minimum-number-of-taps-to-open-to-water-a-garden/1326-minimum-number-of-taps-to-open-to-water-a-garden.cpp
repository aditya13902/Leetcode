class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,1e8);
        dp[0]=0;
        for(int i=0;i<ranges.size();i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            for(int j=l;j<=r;j++){
                dp[j]=min(dp[j],1+dp[l]);
            }
        }
        return dp[n]==1e8?-1:dp[n];
    }
};