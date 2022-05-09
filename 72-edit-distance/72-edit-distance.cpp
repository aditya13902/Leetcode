class Solution {
public:
    int minDistance(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<=text1.size();i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=text2.size();j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};