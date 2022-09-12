class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,vector<int>&vec){
        if(idx==nums.size()){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[idx]);
        helper(nums,idx+1,vec);
        vec.pop_back();
        helper(nums,idx+1,vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        helper(nums,0,vec);
        return ans;
    }
};