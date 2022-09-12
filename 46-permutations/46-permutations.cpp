class Solution {
public:
    void helper(vector<int>&arr,int idx,vector<vector<int>>&ans){
        if(idx==arr.size()){
            // base condition
            ans.push_back(arr);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            swap(arr[i],arr[idx]);
            helper(arr,idx+1,ans);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,0,ans);
        return ans;
    }
};