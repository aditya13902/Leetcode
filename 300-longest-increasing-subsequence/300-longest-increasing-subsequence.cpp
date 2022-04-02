class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};