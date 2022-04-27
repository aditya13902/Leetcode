class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    int cnt=0;
                    if(i==0 || j==0){
                        cnt=1;
                    }
                    else{
                        cnt=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});   
                    }
                    ans+=cnt;
                    dp[i][j]=cnt;
                }
            }
        }
        return ans;
        
    }
};