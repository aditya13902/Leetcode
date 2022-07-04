class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return "";
        }
        int siz=0;
        string ans="";
        // ans+=s[0];
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),false));
        // for(int i=0;i<s.size();)
        int sidx=0;
        for(int l=1;l<=s.size();l++){
            for(int i=0;i<=s.size()-l;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(i==j || i+1==j || dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                else{
                    dp[i][j]=false;
                }
                if( dp[i][j] && l>siz){
                    sidx=i;
                    siz=l;
                }
            }
        }
        return s.substr(sidx,siz);
    }
};