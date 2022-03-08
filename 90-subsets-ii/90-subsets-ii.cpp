class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& nums,vector<int>&subans,int idx){
        int n=nums.size();
        if(idx>=n){
            ans.push_back(subans);
            return;
        }
        int i=idx;
        while(i<n && nums[idx]==nums[i]){
            i++;
        }
        subans.push_back(nums[idx]);
        helper(nums,subans,idx+1);
        subans.pop_back();
        helper(nums,subans,i);
            
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subans;
        sort(nums.begin(),nums.end());
        helper(nums,subans,0);
        return ans;
    }
};