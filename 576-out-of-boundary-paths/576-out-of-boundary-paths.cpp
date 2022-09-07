const int mod=1e9+7;
class Solution {
public:
    vector<vector<vector<int>>>dp;
    int rec(int m,int n,int cnt,int i,int j){
        if(i>=m || j>=n || i<0 || j<0) return 1;
        if(cnt==0) return 0;
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        int a=rec(m,n,cnt-1,i+1,j);
        int b=rec(m,n,cnt-1,i-1,j);
        int c=rec(m,n,cnt-1,i,j+1);
        int d=rec(m,n,cnt-1,i,j-1);
        return dp[i][j][cnt]=((a+b)%mod+(c+d)%mod)%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        dp.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return rec(m,n,maxMove,i,j);
    }
};