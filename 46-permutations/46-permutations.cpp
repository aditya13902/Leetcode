class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&arr,int idx){
        if(idx==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            swap(arr[idx],arr[i]);
            helper(arr,idx+1);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};