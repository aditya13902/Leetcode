class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>&nums,vector<int>&mul,int i,int j,int idx){
        if(idx==mul.size()){
            return 0;
        }
        if(i>j){
            return -1e8;
        }
        if(dp[i][idx]!=INT_MIN) return dp[i][idx];
        return dp[i][idx]=max(nums[i]*mul[idx]+helper(nums,mul,i+1,j,idx+1),nums[j]*mul[idx]+helper(nums,mul,i,j-1,idx+1));
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m=mul.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return helper(nums,mul,0,nums.size()-1,0);
    }
};