class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums,int idx){
        vector<vector<int>>subans;
        if(idx<0){
            vector<int>vec;
            subans.push_back(vec);
            return subans;
        }
        vector<vector<int>>vec=helper(nums,idx-1);
        for(auto ele:vec){
            subans.push_back(ele);
            ele.push_back(nums[idx]);
            subans.push_back(ele);
        }
        return subans;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,nums.size()-1);
    }
};