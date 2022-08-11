class Solution {
public:
    vector<int>dp;
    bool helper(vector<int>&nums,int i,int n){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(i+1<n && nums[i+1]==nums[i]){
            ans|=helper(nums,i+2,n);
        }
        if(i+2<n && nums[i+1]==nums[i] && nums[i+2]==nums[i+1]){
            ans|=helper(nums,i+3,n);
        }
        if(i+2<n && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i+1]+1){
            ans|=helper(nums,i+3,n);
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return helper(nums,0,nums.size());
    }
};