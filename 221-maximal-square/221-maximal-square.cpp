class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1;
                    ans=1;
                }
            }
        }
        
        for(int i=matrix.size()-2;i>=0 ;i--){
            for(int j=matrix[0].size()-2;j>=0;j--){
                if(dp[i][j]==1){
                    dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                }
                ans=max(dp[i][j],ans);
                
            }
        }
        return ans*ans;
    }
};