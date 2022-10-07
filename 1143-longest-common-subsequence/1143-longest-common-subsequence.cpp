class Solution {
public:
    vector<vector<int>>dp;
    // int rec(string &s,string &t,int i,int j){
    //     if(i==s.size() || j==t.size()) return 0;
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     int ans=max(rec(s,t,i+1,j),rec(s,t,i,j+1));
    //     if(s[i]==t[j]){
    //         ans=max(ans,1+rec(s,t,i+1,j+1));
    //     }
    //     return memo[i][j]=ans;
    // }
    int longestCommonSubsequence(string text1, string text2) {
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
};