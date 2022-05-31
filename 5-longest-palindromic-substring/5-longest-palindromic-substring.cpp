class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return s;
        }
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(i==j){
                    dp[i][j]=1;
                }
            }
        }
        int ans=1;
        string str="";
        str+=s[0];
        for(int l=2;l<=s.size();l++){
            for(int i=s.size()-l;i>=0;i--){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(i+1==j){
                        dp[i][j]=2;
                    }
                    else{
                        if(dp[i+1][j-1]!=0){
                            dp[i][j]=2+dp[i+1][j-1];
                        }
                    }
                }
                if(dp[i][j]>ans){
                    ans=dp[i][j];
                    str=s.substr(i,l);
                }
                
            }
        }
        return str;
    }
};