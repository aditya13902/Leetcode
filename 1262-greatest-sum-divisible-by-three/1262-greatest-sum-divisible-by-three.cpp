class Solution {
public:
    vector<vector<int>>dp;
//     int helper(vector<int>&nums,int idx,int curr){ // curr=curr_sum%3
//         if(idx==nums.size()) return curr==0?0:INT_MIN;
//         if(dp[idx][curr]!=-1) return dp[idx][curr];
//         int op1=nums[idx]+helper(nums,idx+1,(curr+nums[idx])%3);
//         int op2=helper(nums,idx+1,curr);
//         return dp[idx][curr]=max(op1,op2);
        
//     }
    int maxSumDivThree(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(3,-1));
        // return helper(nums,0,0);
        dp[0][0]=0;
        dp[0][1]=INT_MIN;
        dp[0][2]=INT_MIN;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][(nums[i-1])%3]+nums[i-1]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][(nums[i-1]+1)%3]+nums[i-1]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][(nums[i-1]+2)%3]+nums[i-1]);
        }
        return dp[n][0];
    }
};