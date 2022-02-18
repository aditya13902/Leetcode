class Solution {
public:
    map<pair<int,int>,int>mp;
    int helper(vector<int>&nums,int idx,int sum,int target){
        if(idx==nums.size()){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(mp.find({idx,sum})!=mp.end()){
            return mp[{idx,sum}];
        }
        return mp[{idx,sum}]=helper(nums,idx+1,sum+nums[idx],target)+helper(nums,idx+1,sum-nums[idx],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int sum=0;
        // for(auto ele:nums){
        //     sum+=ele;
        // }
        // int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(sum,-1));
        return helper(nums,0,0,target);
    }
};