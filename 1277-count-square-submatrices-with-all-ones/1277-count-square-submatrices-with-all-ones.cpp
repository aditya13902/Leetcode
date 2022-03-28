class Solution {
private:
    int row;
    int col;
    vector<vector<int>>dp;
    vector<vector<int>> mat;
    int dfs(int i,int j){
        if(i>=row || j>=col || mat[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=1+min(dfs(i+1,j),min(dfs(i,j+1),dfs(i+1,j+1)));
        return dp[i][j];
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        mat=matrix;
        row=mat.size();
        col=mat[0].size();
        int cnt=0;
        dp.resize(row+1,vector<int>(col+1,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cnt+=dfs(i,j);
            }
        }
        return cnt;
    }
};