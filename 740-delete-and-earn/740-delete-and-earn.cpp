class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>vec(n);
        vector<int>sum(n,0);
        for(auto ele:nums){
            sum[ele]+=ele;
        }
        vector<int>dp(n);
        dp[0]=sum[0];
        dp[1]=sum[1];
        for(int i=2;i<n;i++){
            dp[i]=max(sum[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};