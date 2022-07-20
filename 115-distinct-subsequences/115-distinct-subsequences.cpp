class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>>dp(s.size()+1,vector<unsigned int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                dp[i][j]+=dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};