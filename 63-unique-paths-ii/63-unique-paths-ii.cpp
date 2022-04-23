class Solution {
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& matrix,int i,int j){
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            if(matrix[i][j]==1){
                return 0;
            }
            return 1;
        }
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=helper(matrix,i+1,j)+helper(matrix,i,j+1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        return helper(matrix,0,0);
    }
};