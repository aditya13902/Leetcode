class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        int c=triangle[r-1].size();
        vector<vector<int>>dp(r,vector<int>(c,INT_MIN));
        int ans=INT_MAX;
        for(int i=0;i<c;i++){
            dp[r-1][i]=triangle[r-1][i];
            ans=min(ans,triangle[r-1][i]);
        }
        for(int i=r-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                ans=dp[i][j];
            }
        }
        return ans;
    }
};