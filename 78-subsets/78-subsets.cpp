class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,vector<int>subans){
        if(idx>=nums.size()){
            ans.push_back(subans);
            return;
        }
        helper(nums,idx+1,subans);
        subans.push_back(nums[idx]);
        helper(nums,idx+1,subans);
        // subans.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subans;
        helper(nums,0,subans);
        return ans;
    }
};