class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    // cout<<"yes"<<endl;
                    ans=1;
                    dp[i][j]=1;
                }
            }
        }
        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                if(dp[i][j]==1){
                    // cout<<"yes"<<endl;
                    dp[i][j]=1+min({dp[i+1][j],dp[i+1][j+1],dp[i][j+1]});
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
        
        
    }
};