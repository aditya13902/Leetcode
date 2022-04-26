class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(auto w:wordDict){
                if(i>=w.size()){
                    string str=s.substr(i-w.size(),w.size());
                    if(str==w && dp[i-w.size()]){
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[n];
    }
};