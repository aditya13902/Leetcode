class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),0));
        // dp[0][0]=1;
        int f=0;
        for(int i=0;i<text2.size();i++){
            if(text2[i]==text1[0]) f=1;
            dp[0][i]=f;
        }
        f=0;
        for(int i=0;i<text1.size();i++){
            if(text1[i]==text2[0]) f=1;
            dp[i][0]=f;
        }
        for(int i=1;i<text1.size();i++){
            for(int j=1;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};