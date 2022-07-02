class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& candidate,int tar,int sum,vector<int>subans,int idx){
        if(tar==sum){
            ans.push_back(subans);
            return;
        }
        if(tar<sum || idx>=candidate.size()){
            return;
        }
        subans.push_back(candidate[idx]);
        solve(candidate,tar,sum+candidate[idx],subans,idx+1);
        subans.pop_back();
        int i=idx;
        while(i<candidate.size() && candidate[i]==candidate[idx]){
            i++;
        }
        solve(candidate,tar,sum,subans,i);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidate, int target) {
        vector<int>subans;
        sort(candidate.begin(),candidate.end());
        solve(candidate,target,0,subans,0);
        return ans;
    }
};