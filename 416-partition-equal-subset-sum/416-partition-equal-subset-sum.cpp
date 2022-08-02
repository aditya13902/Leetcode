class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele:nums) sum+=ele;
        if(sum%2 || nums.size()<2) return false;
        int n=nums.size();
        int curr=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(curr+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=curr;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0){
                    dp[i][j]|=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][curr];
    }
};