class Solution {
public:
    int rob(vector<int>& nums) {
        int siz=nums.size();
        vector<int>dp(siz);
        dp[0]=nums[0];
        if(siz>1){
            dp[1]=max(nums[0],nums[1]);
        }
        for(int i=2;i<siz;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[siz-1];
    }
};