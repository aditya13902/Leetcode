class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele:nums) sum+=ele;
        if(sum%2) return false;
        int tar=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(tar+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=1;
        }
        if(tar>=nums[0]) dp[0][nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=tar;j++){
                dp[i][j]=dp[i-1][j] || ((j>=nums[i])? dp[i-1][j-nums[i]]: 0);
            }
        }
        return dp[nums.size()-1][tar];
    }
};