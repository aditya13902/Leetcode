class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele:nums){
            sum+=ele;
        }
        if(sum%2){
            return false;
        }
        sum/=2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
                
            }
        }
        return dp[n][sum];
    }
};