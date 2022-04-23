class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            dp[i]=n;
            for(int j=1;j<=nums[i] && i+j<n;j++){
                dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0]==INT_MAX?-1:dp[0];
    }
};