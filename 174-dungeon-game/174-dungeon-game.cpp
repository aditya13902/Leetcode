class Solution {
public:
    int helper(vector<vector<int>>& mat){
        
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1){
                    dp[i][j]=min(0,mat[i][j]);
                }
                else if(i==r-1){
                    dp[i][j]=min(0,mat[i][j]+dp[i][j+1]);
                }
                else if(j==c-1){
                    dp[i][j]=min(0,mat[i][j]+dp[i+1][j]);
                }
                else{
                    dp[i][j]=min(0,mat[i][j]+max(dp[i][j+1],dp[i+1][j]));
                }
            }
        }
        return abs(dp[0][0])+1;
        
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        return helper(mat);
    }
};