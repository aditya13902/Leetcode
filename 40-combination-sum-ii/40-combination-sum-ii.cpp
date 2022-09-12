class Solution {
public:
    
    void helper(vector<int>&candidates,int i,int target,int sum,vector<int>&vec,vector<vector<int>>&ans){
        if(target==sum){
            ans.push_back(vec);
            return;
        }
        if(i==candidates.size() || sum>target){
            return;
        }
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[i]){
            j++;
        }
        helper(candidates,j,target,sum,vec,ans);
        vec.push_back(candidates[i]);
        helper(candidates,i+1,target,sum+candidates[i],vec,ans);
        vec.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>vec;
        vector<vector<int>>ans;
        helper(candidates,0,target,0,vec,ans);
        return ans;
    }
};