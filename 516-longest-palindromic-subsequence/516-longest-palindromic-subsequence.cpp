class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s,int i,int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=2+helper(s,i+1,j-1);
        }
        return dp[i][j]=max(helper(s,i+1,j),helper(s,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1);
    }
};