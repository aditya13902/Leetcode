class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,vector<int>&sub){
        if(idx==nums.size()){
            ans.push_back(sub);
            return ;
        }
        sub.push_back(nums[idx]);
        helper(nums,idx+1,sub);
        sub.pop_back();
        int i=idx;
        for(i=idx;i<nums.size() && nums[idx]==nums[i];i++){}
        helper(nums,i,sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sub;
        helper(nums,0,sub);
        return ans;
    }
};