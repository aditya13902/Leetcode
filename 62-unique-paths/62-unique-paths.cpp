class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     dp[m-1][i]=1;
        // }
        // for(int i=0;i<m;i++){
        //     dp[i][n-1]=1;
        // }
        vector<int>prev(n,1);
        for(int i=m-2;i>=0;i--){
            vector<int>curr(n,0);
            curr[n-1]=1;
            for(int j=n-2;j>=0;j--){
                curr[j]=prev[j]+curr[j+1];
            }
            prev=curr;
        }
        return prev[0];
    }
};