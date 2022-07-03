class Solution {
public:
    
    int helper(vector<int>& nums,int idx,int f,vector<vector<int>>&dp){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx][f]!=-1){
            return dp[idx][f];
        }
        if(f){
            int ans=1+helper(nums,idx+1,f,dp);
            if(nums[idx+1]>nums[idx]){
                ans=min(ans,helper(nums,idx+1,!f,dp));
            }
            dp[idx][f]=ans;
            return ans;
        }
        else{
            int ans=1+helper(nums,idx+1,f,dp);
            if(nums[idx+1]<nums[idx]){
                ans=min(ans,helper(nums,idx+1,!f,dp));
            }
            dp[idx][f]=ans;
            return ans;
        }
        return dp[idx][f];
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        int ans=INT_MAX;
        for(int i=0;i<=1;i++){
            vector<vector<int>>dp;
            dp.resize(nums.size(),vector<int>(2,-1));
            ans=min(ans,helper(nums,0,i,dp));
        }
        return nums.size()-ans;
    }
};