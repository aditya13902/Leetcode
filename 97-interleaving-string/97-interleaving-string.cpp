class Solution {
public:
    vector<vector<int>>dp;
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        if(n+m !=s3.size()){
            return false;
        }
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    if(s2[j-1]==s3[i+j-1] && dp[i][j-1]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else if(j==0){
                    if(s1[i-1]==s3[i+j-1] && dp[i-1][j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if((s2[j-1]==s3[i+j-1] && dp[i][j-1]) || (s1[i-1]==s3[i+j-1] && dp[i-1][j])){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        return dp[n][m];
        
    }
};