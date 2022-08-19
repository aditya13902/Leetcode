class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,int sum,int target,vector<int>&subans){
        if(sum==target){
            ans.push_back(subans);
            return;
        }
        if(sum>target || idx>=nums.size()) return;
        
        subans.push_back(nums[idx]);
        helper(nums,idx+1,sum+nums[idx],target,subans);
        subans.pop_back();
        int i=idx;
        while(i<nums.size() && nums[i]==nums[idx]) i++;
        helper(nums,i,sum,target,subans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>subans;
        helper(nums,0,0,target,subans);
        return ans;
    }
};