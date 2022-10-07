class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int ans=1;
        int strt=0;
        int len=1;
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(i==j){
                        dp[i][j]=1;
                    }
                    else if(i+1==j){
                        dp[i][j]=2;
                    }
                    else if(dp[i+1][j-1]>0){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
                else{
                    
                }
                if(dp[i][j]>ans){
                    ans=dp[i][j];
                    strt=i;
                    len=j-i+1;
                }
            }
        }
        return s.substr(strt,len);
    }
};