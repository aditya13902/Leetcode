class Solution {
public:
    int dp[20005];
    int helper(vector<int>&nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int curr = nums[i];
        int idx=i;
        int sum=0;
        while(idx<nums.size() && nums[idx]==curr){
            sum+=nums[idx];
            idx++;
        }
        while(idx<nums.size() && nums[idx]==curr+1){
            idx++;
        }
        return dp[i]=max(sum+helper(nums,idx),helper(nums,i+1));
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return helper(nums,0);
        
    }
};