class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1));
        dp[0][0]=1;
        // for(int i=0;i<=n;i++){
        //     if()
        // }
        for(int j=1;j<=m;j++){
            if(p[j-1]!='*') break;
            dp[0][j]=1;
            // cout<<"y"<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};