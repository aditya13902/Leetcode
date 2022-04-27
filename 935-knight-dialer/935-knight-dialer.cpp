class Solution {
    vector<vector<vector<int>>>dp;
    int mod=1000000007;
    int helper(int n,int i,int j){
        if(i<0 || i>=4 || j<0 || j>=3){
            return 0;
        }
        if(i==3 && (j==0 || j==2)){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n][i][j]!=-1){
            return dp[n][i][j];
        }
        dp[n][i][j]=((((((((helper(n-1,i+2,j+1)+helper(n-1,i+2,j-1))%mod+helper(n-1,i-2,j+1))%mod+helper(n-1,i-2,j-1))%mod+helper(n-1,i+1,j+2))%mod+helper(n-1,i-1,j+2))%mod+helper(n-1,i+1,j-2))%mod+helper(n-1,i-1,j-2))%mod)%mod;
        return dp[n][i][j];
    }
public:
    int knightDialer(int n) {
        dp.resize(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
        int cnt=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                cnt=(cnt+helper(n-1,i,j))%mod;
            }
        }
        return cnt;
    }
};