class Solution {
public:
    vector<int>dp;
    int helper(string s,int i){
        if(i>=s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=helper(s,i+1);
        if(i+2<=s.size() && s.substr(i,2)<="26"){
            ans+=helper(s,i+2);
        }
        return dp[i]=ans;
        
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return helper(s,0);
    }
};