class Solution {
private:
    vector<vector<int>>dp;
    int row;
    int col;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        row=matrix.size();
        col=matrix[0].size();
        dp.resize(row,vector<int>(col));
        for(int i=0;i<col;i++){
            dp[row-1][i]=matrix[row-1][i];
        }
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<col;j++){
                dp[i][j]=dp[i+1][j];
                if(j+1<col){
                    dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
                }
                if(j-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }
                dp[i][j]+=matrix[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<col;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};