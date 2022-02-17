class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&candidates,int target,vector<int>&subans,int sum,int idx){
        if(target<sum){
            return;
        }
        if(target==sum){
            ans.push_back(subans);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(sum+candidates[i]<=target){
                subans.push_back(candidates[i]);
                helper(candidates,target,subans,sum+candidates[i],i);
                subans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subans;
        helper(candidates,target,subans,0,0);
        return ans;
    }
};