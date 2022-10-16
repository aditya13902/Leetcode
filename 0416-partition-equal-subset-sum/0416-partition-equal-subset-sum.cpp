class Solution {
public:
    vector<vector<int>>dp;
    bool helper(vector<int>&nums,int idx,int sum){
        if(sum==0) return true;
        if(idx==nums.size() || sum<0) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=helper(nums,idx+1,sum-nums[idx]) || helper(nums,idx+1,sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele:nums) sum+=ele;
        
        if(sum&1) return false;
        sum=sum/2;
        dp.resize(nums.size(),vector<int>(sum+1,-1));
        return helper(nums,0,sum);
        
    }
};