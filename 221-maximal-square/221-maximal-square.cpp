class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1;
                    ans=1;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int curr=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                // int curr=0;
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+curr;
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans*ans;
    }
};