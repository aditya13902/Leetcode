class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
        for(int l=2;l<=s.size();l++){
            for(int i=0;i<=s.size()-l;i++){
                int j=i+l-1;
                if(s[i]==s[j] && (i+1==j || dp[i+1][j-1])){
                    dp[i][j]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(dp[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};