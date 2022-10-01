class Solution {
public:
    vector<int>dp;
    int helper(string &s,int i){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=helper(s,i+1);
        if(i+1<s.size() && s.substr(i,2)<="26"){
            ans+=helper(s,i+2);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='0'){
                dp[i]+=dp[i+1];
                if(i+2<=n && s.substr(i,2)<="26"){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
};