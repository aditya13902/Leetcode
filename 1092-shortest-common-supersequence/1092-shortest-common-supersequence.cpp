class Solution {
public:
    vector<vector<int>>dp;

    int lcs(string text1, string text2) {
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                }
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[text1.size()][text2.size()];
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // dp.resize(str1.size(),vector<int>(str2.size()));
        lcs(str1,str2);
        int i=str1.size();
        int j=str2.size();
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans=ans+str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans=ans+str1[i-1];
                    i--;
                }
                else{
                    ans=ans+str2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            ans=ans+str1[i-1];
            i--;
        }
        while(j>0){
            ans=ans+str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};