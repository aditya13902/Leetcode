class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int cnt=0;
                    if(i==0 || j==0){
                        cnt=1;
                    }
                    else{
                        cnt=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    }
                    ans+=cnt;
                    dp[i][j]=cnt;
                }
            }
        }
        return ans;
    }
};