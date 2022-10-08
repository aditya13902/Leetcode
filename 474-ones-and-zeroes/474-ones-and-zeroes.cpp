class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(vector<string>&strs,int m,int n,int i){
        if(m==0 && n==0){
            return 0;
        }
        if(i==strs.size()) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int cnt0=0;
        int cnt1=0;
        for(auto ch:strs[i]){
            cnt0=(ch=='0')?cnt0+1:cnt0;
            cnt1=(ch=='1')?cnt1+1:cnt1;
        }
        int ans=helper(strs,m,n,i+1);
        if(cnt0<=m && cnt1<=n){
            ans=max(ans,1+helper(strs,m-cnt0,n-cnt1,i+1));
        }
        return dp[m][n][i]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return helper(strs,m,n,0);
    }
};