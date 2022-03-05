class Solution {
public:
//     int dp[20005];
//     int helper(vector<int>&nums,int i){
//         if(i>=nums.size()){
//             return 0;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int idx=i;
//         int sum=0;
//         while(idx<nums.size() && nums[idx]==nums[i]){
//             sum+=nums[idx];
//             idx++;
//         }
//         while(idx<nums.size() && nums[idx]==nums[i]+1){
//             idx++;
//         }
//         return dp[i]=max(sum+helper(nums,idx),helper(nums,i+1));
        
//     }
//     int deleteAndEarn(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         memset(dp,-1,sizeof(dp));
//         return helper(nums,0);
        
//     }
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;

        //take the total sum by each number
        vector<int> sum(n, 0);
        vector<int> dp(n, 0);

        for(auto num: nums){
            sum[num] += num;
        }

        dp[0] = 0;
        dp[1] = sum[1];
        //now apply the house robbing concept
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
        }

        return dp[n-1];
    }
};
