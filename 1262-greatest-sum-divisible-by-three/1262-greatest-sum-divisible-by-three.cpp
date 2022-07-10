
class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<int>&nums,int idx,int curr){
        if(idx==nums.size()){
            if(curr==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        int a,b;
        a=rec(nums,idx+1,curr);
        b=nums[idx]+rec(nums,idx+1,(curr+nums[idx])%3);
        return dp[idx][curr]=max(a,b);
    }
    int maxSumDivThree(vector<int>& nums) {
        
        dp.resize(nums.size(),vector<int>(3,-1));
        return rec(nums,0,0);
    }
};