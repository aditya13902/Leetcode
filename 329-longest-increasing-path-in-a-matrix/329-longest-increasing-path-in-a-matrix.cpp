class Solution {
public:
    vector<vector<int>>dp;
    int pathfind(vector<vector<int>>&mat,int i,int j,int prev){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(mat[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=pathfind(mat,i+1,j,mat[i][j]);
        int b=pathfind(mat,i-1,j,mat[i][j]);
        int c=pathfind(mat,i,j+1,mat[i][j]);
        int d=pathfind(mat,i,j-1,mat[i][j]);
        return dp[i][j]=1+max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,pathfind(matrix,i,j,-1));
            }
        }
        return ans;
    }
};