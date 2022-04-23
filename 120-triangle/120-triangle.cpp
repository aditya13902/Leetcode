class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& triangle,int r,int c){
        if(r>=triangle.size()){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int a=triangle[r][c]+helper(triangle,r+1,c);
        int b=triangle[r][c]+helper(triangle,r+1,c+1);
        return dp[r][c]=min(a,b);     
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(triangle.size(),vector<int>(triangle.size(),-1));
        return helper(triangle,0,0);
    }
};