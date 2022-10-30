class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int l=1;l<=s.size();l++){
            for(int i=0;i<=s.size()-l;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(i==j){
                        dp[i][j]=1;
                    }
                    else if(i+1==j){
                        dp[i][j]=1;
                    }
                    else{
                        if(dp[i+1][j-1]){
                            dp[i][j]=1;
                        }
                        else{
                            dp[i][j]=0;
                        }
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};