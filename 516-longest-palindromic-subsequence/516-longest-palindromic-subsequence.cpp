class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    dp[i][j]=max(dp[i][j],2+((i+1==j)?0:dp[i+1][j-1]));
                }
                dp[i][j]=max({dp[i][j],dp[i+1][j],dp[i][j-1]});
            }
        }
        return dp[0][s.size()-1];
    }
};