class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto&w:wordDict){
                if(i>=w.size()){
                    string str=s.substr(i-w.size(),w.size());
                    if(str==w && dp[i-w.size()]){
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[n];
    }
};