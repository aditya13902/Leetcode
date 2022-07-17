class Solution {
public:
    vector<int>dp;
    int helper(vector<int>&arr,int idx,int k){
        if(idx==arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mx=0;
        int ans=0;
        for(int i=idx;i<idx+k && i<arr.size();i++){
            mx=max(mx,arr[i]);
            ans=max(ans,mx*(i-idx+1)+helper(arr,i+1,k));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return helper(arr,0,k);
    }
};