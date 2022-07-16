class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++) dp[i][i]=1;
        for(int l=2;l<=s.size();l++){
            for(int i=0;i<=s.size()-l;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2) dp[i][j]=2;
                    else{
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        int n=s.size();
        return s.size()-dp[0][n-1];
    }
};