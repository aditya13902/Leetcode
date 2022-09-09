const int mod=1e9+7;
class Solution {
public:
    vector<vector<int>>dp;
    int helper(string& s,int idx,int cnt,int curr,int tot){
        if(idx==s.size()){
            return tot==3;
        }
        if(tot>3) return 0;
        if(dp[idx][tot]!=-1) return dp[idx][tot];
        if(s[idx]=='1'){
            int ans=0;
            if(curr==cnt){
                ans+=helper(s,idx+1,cnt,1,tot+1);
            }
            else{
                ans+=helper(s,idx+1,cnt,curr+1,tot);
            }
            return dp[idx][tot]=ans;
        }
        else{
            int ans=0;
            if(curr==cnt){
                ans+=helper(s,idx+1,cnt,0,tot+1);
            }
            ans=(ans+helper(s,idx+1,cnt,curr,tot))%mod;
            return dp[idx][tot]=ans;
        }
    }
    int numWays(string s) {
        int cnt=0;
        int n=s.size();
        for(auto ch:s){
            if(ch=='1') cnt++;
        }
        if(cnt%3) return 0;
        if(cnt==0){
            return (((n-1) * 1LL * (n-2) * 1LL) / 2) % mod;
        }
        dp.resize(s.size(),vector<int>(5,-1));
        return helper(s,0,cnt/3,0,1);
    }
};