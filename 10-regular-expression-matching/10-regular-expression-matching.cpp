class Solution {
public:
    vector<vector<int>>dp;
    bool helper(string &s,string &p,int i,int j){
        if(j==p.size() && i==s.size()) return true;
        if(j==p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j+1<p.size() && p[j+1]=='*'){
            bool ans=false;
            if(i<s.size() && (s[i]==p[j] || p[j]=='.')){
                ans=ans || helper(s,p,i+1,j);
            }
            ans=ans || helper(s,p,i,j+2);
            return dp[i][j]=ans;
        }
        else if(i<s.size()  && (s[i]==p[j] || p[j]=='.')){
            return dp[i][j]=helper(s,p,i+1,j+1);
        }
        else {
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(s,p,0,0);
    }
};