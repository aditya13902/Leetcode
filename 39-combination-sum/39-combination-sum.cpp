class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,int sum,int target,vector<int>&subans){
        if(sum>target || idx>=nums.size()) return;
        if(sum==target){
            ans.push_back(subans);
            return;
        }
        subans.push_back(nums[idx]);
        helper(nums,idx,sum+nums[idx],target,subans);
        subans.pop_back();
        helper(nums,idx+1,sum,target,subans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subans;
        helper(nums,0,0,target,subans);
        return ans;
    }
};