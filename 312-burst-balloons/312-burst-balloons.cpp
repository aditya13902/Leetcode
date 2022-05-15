class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&nums,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mx=0;
        for(int idx=i;idx<=j;idx++){
            int ans=nums[i-1]*nums[idx]*nums[j+1]+helper(nums,i,idx-1)+helper(nums,idx+1,j);
            mx=max(ans,mx);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,1,nums.size()-2);
    }
};