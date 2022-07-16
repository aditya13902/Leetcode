class Solution {
public:
    vector<vector<int>>dp;
    bool helper(vector<int>&nums,int sum,int idx){
        if(sum==0) return true;
        if(sum<0) return false;
        if(idx==nums.size()) return false;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=helper(nums,sum-nums[idx],idx+1) || helper(nums,sum,idx+1);
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(auto ele:nums){
            tot+=ele;
        }
        if(tot%2){
            return false;
        }
        int sum=tot/2;
        dp.resize(nums.size(),vector<int>(sum+1,-1));
        return helper(nums,sum,0);
        
        
    }
};