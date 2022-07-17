class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,0);
        dp[1]=arr[0];
        for(int i=2;i<=arr.size();i++){
            int currmx=0;
            for(int j=1;j<=k && i-j>=0;j++){
                currmx=max(currmx,arr[i-j]);
                dp[i]=max(dp[i],currmx*j+dp[i-j]);
            }
        }
        return dp[arr.size()];
    }
};