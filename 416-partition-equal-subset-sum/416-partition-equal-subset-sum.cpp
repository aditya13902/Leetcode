class Solution {
public:
    vector<vector<int>>dp;
    bool divide(vector<int>&nums,int tot,int idx){
        if(tot==0) return true;
        if(idx==nums.size()){
            return false;
        }
        if(tot<0){
            return false;
        }
        if(dp[tot][idx]!=-1){
            return dp[tot][idx];
        }
        return dp[tot][idx]=divide(nums,tot-nums[idx],idx+1) || divide(nums,tot,idx+1);
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(auto ele:nums){
            tot+=ele;
        }
        if(tot%2){
            return false;
        }
        dp.resize((tot/2)+1,vector<int>(nums.size(),-1));
        return divide(nums,tot/2,0);
        
    }
};