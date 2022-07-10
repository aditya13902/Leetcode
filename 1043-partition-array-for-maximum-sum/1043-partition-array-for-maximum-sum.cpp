class Solution {
private:
    vector<int>dp;
    int helper(vector<int>&arr,int i,int k){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mx=-1;
        for(int j=i;j<arr.size() && j<i+k;j++){
            mx=max(mx,arr[j]);
            dp[i]=max(dp[i],(j-i+1)*mx+helper(arr,j+1,k));
        }
        return dp[i];
    }
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return helper(arr,0,k);
    }
};