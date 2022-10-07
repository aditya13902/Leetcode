class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s,int l,int r){
        if(l>r) return 0;
        if(l==r) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
            return 2+helper(s,l+1,r-1);
        }
        return dp[l][r]=max(helper(s,l+1,r),helper(s,l,r-1));
    }
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1);
    }
};