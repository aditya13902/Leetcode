class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    dp[i][j]=1;
                }
            }
        }
        
        int ans=0;
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                if(matrix[i][j]){
                    dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                    
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // cout<<dp[i][j]<<" ";
                cnt+=dp[i][j];
            }
            // cout<<e/ndl;
        }
        return cnt;
    }
};