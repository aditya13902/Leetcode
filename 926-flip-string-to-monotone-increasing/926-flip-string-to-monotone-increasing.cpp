class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s,int idx,int f){
        if(idx==s.size()) return 0;
        int ans=s.size();
        if(dp[idx][f]!=-1) return dp[idx][f];
        if(f){
            if(s[idx]=='1'){
                ans=min(ans,helper(s,idx+1,f));
            }
            else{
                ans=min(ans,1+helper(s,idx+1,f));
            }
        }
        else{
            if(s[idx]=='1'){
                ans=min(ans,min(1+helper(s,idx+1,f),helper(s,idx+1,!f)));
            }
            else{
                ans=min(ans,min(helper(s,idx+1,f),1+helper(s,idx+1,!f)));
            }
        }
        return dp[idx][f]=ans;
    }
    int minFlipsMonoIncr(string s) {
        dp.resize(s.size(),vector<int>(2,-1));
        return helper(s,0,0);
    }
};