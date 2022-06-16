class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        string str="";
        int ans=1;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        str.push_back(s[0]);
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j=i+l;
                if(s[i]==s[j]){
                    if(i+1==j){
                        dp[i][j]=1;
                    }
                    else if(dp[i+1][j-1]){
                        dp[i][j]=1;
                    }
                }
                else{
                    dp[i][j]=0;
                }
                if(dp[i][j] && j-i+1>ans){
                    str=s.substr(i,j-i+1);
                    // cout<<i<<" "<<j<<endl;
                    ans=l+1;
                }
            }
        }
        return str;
    }
};