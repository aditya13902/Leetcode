class Solution {
public:
    vector<vector<int>>dp;
    // bool divide(vector<int>&nums,int tot,int idx){
    //     if(tot==0) return true;
    //     if(idx==nums.size()){
    //         return false;
    //     }
    //     if(tot<0){
    //         return false;
    //     }
    //     if(dp[tot][idx]!=-1){
    //         return dp[tot][idx];
    //     }
    //     return dp[tot][idx]=divide(nums,tot-nums[idx],idx+1) || divide(nums,tot,idx+1);
    // }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(auto ele:nums){
            tot+=ele;
        }
        if(tot%2){
            return false;
        }
        dp.resize((tot/2)+1,vector<int>(nums.size(),0));
        // return divide(nums,tot/2,0);
        for(int i=0;i<nums.size();i++){
            dp[0][i]=1;
        }
        int sum=tot/2;
        if(nums[0]<=sum){
            dp[nums[0]][0]=1;
        }
        
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                dp[j][i]=dp[j][i-1];
                if(j-nums[i]>=0){
                    dp[j][i]|=dp[j-nums[i]][i-1];
                }
            }
        }
        return dp[tot/2][nums.size()-1];
        
    }
};