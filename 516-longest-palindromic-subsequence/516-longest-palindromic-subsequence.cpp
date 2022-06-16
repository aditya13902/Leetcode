class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int l=1;l<s.size();l++){
            for(int i=0;i<s.size()-l;i++){
                int j=i+l;
                if(s[i]==s[j]){
                    if(i+1==j){
                        dp[i][j]=2;
                    }
                    else if(dp[i+1][j-1]){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }

        }
        return dp[0][n-1];
    }
};
