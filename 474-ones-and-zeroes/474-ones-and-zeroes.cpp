class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(vector<pair<int,int>>&vec,int m,int n,int i){
        if(m==0 && n==0) return 0;
        if(i==vec.size()) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int ans=helper(vec,m,n,i+1);
        if(vec[i].first<=m && vec[i].second<=n){
            ans=max(ans,1+helper(vec,m-vec[i].first,n-vec[i].second,i+1));
        }
        return dp[m][n][i]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        for(auto str:strs){
            int cnt0=0;
            int cnt1=0;
            for(auto ch:str){
                if(ch=='0') cnt0++;
                else cnt1++;
            }
            vec.push_back({cnt0,cnt1});
        }
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(vec.size(),-1)));
        return helper(vec,m,n,0);
    }
};