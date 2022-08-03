class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&nums,int idx,int curr){ // curr=curr_sum%3
        if(idx==nums.size()) return curr==0?0:INT_MIN;
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        int op1=nums[idx]+helper(nums,idx+1,(curr+nums[idx])%3);
        int op2=helper(nums,idx+1,curr);
        return dp[idx][curr]=max(op1,op2);
        
    }
    int maxSumDivThree(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(3,-1));
        return helper(nums,0,0);
    }
};